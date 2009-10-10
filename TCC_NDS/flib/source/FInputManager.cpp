//#include "FLib.h"
//
//void FInputManager::Update()
//{
//	scanKeys();
//	int h = keysHeld();
//	int u = keysUp();
//	int d = keysDown();
//	touchPosition tp;
//	touchRead(&tp);
//
//	Pad.Up.Held     = h & KEY_UP;
//	Pad.Up.Pressed  = d & KEY_UP;
//	Pad.Up.Released = u & KEY_UP;
//
//	Pad.Down.Held     = h & KEY_DOWN;
//	Pad.Down.Pressed  = d & KEY_DOWN;
//	Pad.Down.Released = u & KEY_DOWN;
//
//	Pad.Left.Held     = h & KEY_LEFT;
//	Pad.Left.Pressed  = d & KEY_LEFT;
//	Pad.Left.Released = u & KEY_LEFT;
//
//	Pad.Right.Held     = h & KEY_RIGHT;
//	Pad.Right.Pressed  = d & KEY_RIGHT;
//	Pad.Right.Released = u & KEY_RIGHT;
//
//	Pad.A.Held     = h & KEY_A;
//	Pad.A.Pressed  = d & KEY_A;
//	Pad.A.Released = u & KEY_A;
//
//	Pad.B.Held     = h & KEY_B;
//	Pad.B.Pressed  = d & KEY_B;
//	Pad.B.Released = u & KEY_B;
//
//	Pad.X.Held     = h & KEY_X;
//	Pad.X.Pressed  = d & KEY_X;
//	Pad.X.Released = u & KEY_X;
//
//	Pad.Y.Held     = h & KEY_Y;
//	Pad.Y.Pressed  = d & KEY_Y;
//	Pad.Y.Released = u & KEY_Y;
//
//	Pad.L.Held     = h & KEY_L;
//	Pad.L.Pressed  = d & KEY_L;
//	Pad.L.Released = u & KEY_L;
//
//	Pad.R.Held     = h & KEY_R;
//	Pad.R.Pressed  = d & KEY_R;
//	Pad.R.Released = u & KEY_R;
//
//	Pad.Start.Held     = h & KEY_START;
//	Pad.Start.Pressed  = d & KEY_START;
//	Pad.Start.Released = u & KEY_START;
//
//	Pad.Select.Held     = h & KEY_SELECT;
//	Pad.Select.Pressed  = d & KEY_SELECT;
//	Pad.Select.Released = u & KEY_SELECT;
//
//	Lid.Closed = d & KEY_LID;
//	
//	Touch.Held     = h & KEY_TOUCH;
//	Touch.Pressed  = d & KEY_TOUCH;
//	Touch.Released = u & KEY_TOUCH;
//	Touch.X = tp.px;
//	Touch.Y = tp.py;
//}
