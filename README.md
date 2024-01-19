# 6ECS9
single header ecs library written in pure c (c99)
DA FASTEST
#### Features:
- Written in C99
- Single Header Library
- Fast ASF
- Pure ECS Design
- Simple
- No Dependencies
#### How to use:
`#define MAX_ENTITIES 100` (default: 64)

`#define MAX_COMPONENTS 10` (default: 32)

`#include "6ecs9.h"`
#### Important:
for now the maximum components can be used is 64
ima work on it to handle more than 64
#### Example:
```c
#include "6ecs9.h"

newCompStruct(Position, { float x, y; }); // custom struct
newComp(Sprite, Texture2D); // defined type
newProp(Player); // no data

void MovementSystem(float dt)
{
	Iter(Position)
	{
		// getting address of Position comp and storing it in var named "position" (pointer)
		usingMutComp(Position, position);
		// gravity
		position->y += dt;
	}
}

void RenderingSystem(void)
{
	Iter(Position, Sprite)
	{
		// getting a copy of Position comp, so the original value wont be changed
		usingComp(Position, position);
		usingComp(Sprite, image);
		DrawTexture(image, position);
	}
}

void InputSystem(int Key)
{
	// we going to change player, but we cant use "usingComp(Player)" because it prop
	Iter(Player, Position)
	{
		usingMutComp(Position, position);
		// jumping
		if (Key == SPACE) position->y -= 1.0f;
	}
}

int main(void)
{
	CreateWindow(800, 600);

	Texture2D playerSprite = LoadTexture("player.png");

	newEntity()
		is(Player) // is() for props
		with(Position, {0.0f, 0.0f}) // with for comps
		with(Sprite, playerSprite);
	
	while (!WindowShouldClose())
	{
		MovementSystem(GetFrameTime());
		InputSystem(GetKeyDown());
		RenderingSystem();
	}
}
```

## you woudnt find library better den dis 
