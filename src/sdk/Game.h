#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include "Arena.h"
#include "Keyboard.h"
#include "Timer.h"
#include "BoardMemory.h"
#include "xparameters.h"
#include "xil_types.h"
#include "xil_printf.h"

class Game
{
public:
	Game();
	void Init();
	void Loop();

private:
	Arena arena;
	Keyboard keyboard;
	u8 pressed_key;
	Timer timer;
	uint32_t *arena_drawer;

	void HandleKeyboard();
	void Update(float dt);
	void Draw();
};

#endif /* SRC_GAME_H_ */
