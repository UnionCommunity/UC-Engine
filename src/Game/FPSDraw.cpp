#include "Utils.h"
#include "Component.h"
#include "imgui.h"
#include "imgui-SFML.h"

namespace eng
{

class FPSDraw : public Component
{
    public:

    float time = 0;
    int fps = 0;
    float fpsCounter = 0;
    float fpsTime = 0;
    int objectsCount = 0;

    void Update()
    {
        time += DeltaTime();
        fpsTime += DeltaTime();
    }

    void GUI()
    {
        fpsCounter++;

        if(fpsTime >= 1)
        { 
            fps = fpsCounter;
            fpsCounter = 0;
            fpsTime = 0;
        }

        auto parent = owner.lock();

        if(parent)
        {
            objectsCount = parent->GetScene()->GetGameObjects().size();

            //ImGui::ShowDemoWindow();

            ImGui::Begin("Stats");

            ImGui::SetWindowPos(ImVec2(1500, 10));
            ImGui::SetWindowSize(ImVec2(400, 600));

            string _fps = to_string(fps);
            string _dTime = to_string(DeltaTime());
            string _gameTime = to_string(time);
            string _objectCount = to_string(objectsCount);

            ImGui::LabelText("<---FPS", _fps.c_str());
            ImGui::LabelText("<---DeltaTime", _dTime.c_str());
            ImGui::LabelText("<---Game time", _gameTime.c_str());
            ImGui::LabelText("<---Objects count", _objectCount.c_str());

            ImGui::Columns(2, "ObjectList", true);
            ImGui::Text("Object Name"); ImGui::NextColumn();
            ImGui::Text("Object Position"); ImGui::NextColumn();
            ImGui::Separator();


            for(auto weakObject : parent->GetScene()->GetGameObjects())
            {
                if(auto currObject = weakObject.lock())
                {
                    string pos = "(" + to_string(currObject->transform.position.x) + ";" + to_string(currObject->transform.position.y) + ")";

                    ImGui::Text(currObject->GetName().c_str()); ImGui::NextColumn();
                    ImGui::Text(pos.c_str()); ImGui::NextColumn();
                }
            }

            

            ImGui::End();
        }
    }
};

}