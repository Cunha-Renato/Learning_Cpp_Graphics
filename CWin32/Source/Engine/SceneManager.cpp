#include "..\..\Headers\Engine\SceneManager.h"
#include "..\..\Headers\Engine\Scene.h"
#include "..\..\Headers\Engine\Window.h"

int SceneManager::m_Active_Scene_Index = 0;
Window* SceneManager::m_Window;
std::vector<Scene*> SceneManager::m_Scenes;

SceneManager::SceneManager(Window *window)
{
    m_Window = window;
}

SceneManager::SceneManager(Window *window, std::vector<Scene*> scenes)
{
    m_Window = window;
    m_Scenes = scenes;
}

void SceneManager::add(Scene *scene) 
{
    m_Scenes.push_back(scene);
}

void SceneManager::remove(int index) 
{
    m_Scenes.erase(m_Scenes.begin()+index);
}

void SceneManager::setActiveScene(Scene* scene)
{
    for(int i=0; i<m_Scenes.size(); i++)
        if(m_Scenes[i] == scene)
            m_Active_Scene_Index = i;

    initScene();
}

void SceneManager::setActiveScene(int index)
{
    m_Active_Scene_Index = index;
    initScene();
}

void SceneManager::initScene()
{
    m_Scenes[m_Active_Scene_Index]->setWindow(m_Window);
    m_Scenes[m_Active_Scene_Index]->setGraphics(m_Window->getGraphics());
    m_Scenes[m_Active_Scene_Index]->init();
}

void SceneManager::runInput(bool wasDown, bool isDown, long keyCode)
{
    m_Scenes[m_Active_Scene_Index]->input(wasDown, isDown, keyCode);
}

void SceneManager::runScene()
{
    m_Scenes[m_Active_Scene_Index]->update();
    m_Scenes[m_Active_Scene_Index]->render();
}