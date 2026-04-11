#include "raylib.h"
#include "libQuantuum.h"

int main()
{
    float screenX = 800;
    float screenY = 600;
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(screenX, screenY, "RayLib Example");

    //todo: implement active glcontext validation

    Base base;
    DrawHandler draw;
    Physics physics;
    Application app;

    //* animation
    Animator player_animator;
    player_animator.setup_animation(6, {16,16}, 0.1);
    //* animation end

    entityConfig playerConf = {
        "test/assets/Player_temp.png",
        {0,0},
        {100,100},
        WHITE,
        0,
        {0,0},
        1,
        230,
    };
    Entity player = Entity::create_entity(playerConf);

    while (!WindowShouldClose())
    {
        Vector2 input_dir = Input::GetDirectionalInput();
        player._data.physicsObj.direction = base.Normalize(input_dir);    // Get input
        physics.move(&player._data.physicsObj);                           // Change velocity
        physics.apply_velocity(&player._data); 
        // todo: implement global update system
        player.update_entity_transform();                                 // Set dest_rect to transform.pos
        physics.apply_gravity(&player._data.physicsObj);                  // Add velocity to transform.pos

        #pragma region RUN

        BeginDrawing();
        ClearBackground(SKYBLUE);

        //todo: Implement glContext validation securety!!!
        draw.RenderEntity(player._data);
        // draw.RenderEntityAnimation(player._data, &player_animator);
        // player_animator.animation_update(&player_animator._animation);

        EndDrawing();
    }
    #pragma region EXIT
    CloseWindow();

    ResourceLoader::unloadAll();

    return 0;
}