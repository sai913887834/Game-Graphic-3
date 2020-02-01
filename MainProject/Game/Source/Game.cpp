#include "GamePCH.h"

#include "Game.h"
#include "Base/Mesh.h"
#include "GameObjects/GameObject.h"
//#include "GameObjects/Camera.h"
//#include "GameObjects/Player.h"
#include "GameObjects/PlayerController.h"
#include "GameObjects/ResourceManager.h"
#include"GameObjects/SceneCube.h"
#include"GameObjects/Scene.h"


using namespace fw;

Game::Game(Framework* pFramework)
: GameCore( pFramework )
{
    m_pImGuiManager = nullptr;

    m_pShaderTexture = nullptr;
    m_pMeshBox = nullptr;
    m_pTexture = 0;

   // m_pPlayer = nullptr;
  //  m_pCamera = nullptr;

    m_pSceneCube = nullptr;
    m_pController = new PlayerController();

    m_ResourceManager = new ResourceManager();

    m_Scene = new Scene(this, m_pPhysicsWorld,  false);
}

Game::~Game()
{
    delete m_pController;

   // delete m_pPlayer;
  //  delete m_pCamera;
    delete m_pSceneCube;

    delete m_pTexture;

    delete m_pMeshBox;

    delete m_pShaderTexture;

    delete m_pImGuiManager;
    delete m_pPhysicsWorld;

    delete m_ResourceManager;

    delete m_Scene;
}

void Game::Init()
{
	glEnable(GL_DEPTH_TEST);
    m_pImGuiManager = new ImGuiManager();
    m_pImGuiManager->Init();

    // Turn on v-sync.
    wglSwapInterval( 1 );

    // Create our shaders.
    m_pShaderTexture = new ShaderProgram( "Data/Shaders/texture.vert", "Data/Shaders/texture.frag" );
    m_Scene->LoadScene("Data/Scene/Simple.box2dscene");


    // Create our meshes.
    m_pMeshBox = new Mesh();
    m_pMeshBox->CreateBox( vec3(1,1,1), vec3(0,0,0) );

    // Load our textures.
    m_pTexture = new Texture( "Data/Textures/dice.png" );


    m_ResourceManager->SetMesh("Squre", m_pMeshBox);
    m_ResourceManager->SetShaderProgram("texture shader", m_pShaderTexture);
    m_ResourceManager->SetTexture("dice", m_pTexture);


    // Create our GameObjects.
   // m_pPlayer = new Player( this, m_ResourceManager->GetMesh("Squre"), m_ResourceManager->GetShader("texture shader"), m_ResourceManager->GetTexture("MegaMan"), vec2( 0, 0 ), 0, m_pController );
  //  m_pCamera = new Camera( this, vec2( 0, 0 ), vec2( 1/5.0f, 1/5.0f ) );
	m_pPhysicsWorld = new PhysicsWorld2D();
    m_pSceneCube = new SceneCube(this, m_ResourceManager->GetMesh("Squre"), m_ResourceManager->GetShader("texture shader"), m_ResourceManager->GetTexture("dice"), vec3(0, 0,0), 0, m_pController, vec2(1 / 5.0f, 1 / 5.0f));
    m_ResourceManager->GetTexture("Megaman");
    //Create Physics world
    
}

void Game::OnEvent(Event* pEvent)
{
    m_pController->OnEvent( pEvent );
	//m_pImGuiManager->OnEvent(pEvent);
}

void Game::Update(float deltaTime)
{
    m_pImGuiManager->StartFrame( (float)m_pFramework->GetWindowWidth(), (float)m_pFramework->GetWindowHeight(), deltaTime );

    // Enable/disable V-Sync.
    if( m_pFramework->IsKeyDown( VK_F1 ) )
        wglSwapInterval( 0 );
    if( m_pFramework->IsKeyDown( VK_F2 ) )
        wglSwapInterval( 1 );

    // Update objects.
   // m_pPlayer->Update( deltaTime );
   // m_pCamera->Update( deltaTime );
    m_pSceneCube->Update(deltaTime);
	m_pPhysicsWorld->Update(deltaTime);
}

void Game::Draw()
{
    // Setup the values we will clear to, then actually clear the color and depth buffers.
    glClearColor( 0.0f, 0.0f, 0.4f, 0.0f ); // dark blue
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Enable alpha blending.
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // Draw our game objects.
   // m_pPlayer->Draw( m_pCamera );
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    m_pSceneCube->Draw();

    m_pImGuiManager->EndFrame();
}

PhysicsWorld* Game::GetPhysicsWorld()
{
	return m_pPhysicsWorld;
}

//PhysicsWorld* Game::GetPhysicsWorld()
//{
  //  return m_pPhysicsWorld;
//}
