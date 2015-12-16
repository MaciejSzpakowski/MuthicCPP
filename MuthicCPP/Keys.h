#pragma once
namespace dx2d
{
	struct CKey
	{
		const int MouseLeft = 0x01;
		const int MoueRight = 0x02;
		const int _VK_CANCEL = 0x03;
		const int MouseMiddle = 0x04;
		const int _VK_XBUTTON1 = 0x05;
		const int _VK_XBUTTON2 = 0x06;
		const int BackSpace = 0x08;
		const int Tab = 0x09;
		const int _VK_CLEAR = 0x0C;
		const int Enter = 0x0D; //both enter and num enter have the same code
		const int Shift = 0x10; //both left and right
		const int Control = 0x11;//ctrl, both l and r
		const int Alt = 0x12; //alt, both l and r
		const int PauseBreak = 0x13; //better dont use this
		const int CapsLock = 0x14;
		const int _VK_KANA = 0x15;
		const int _VK_HANGEUL = 0x15;
		const int _VK_HANGUL = 0x15;
		const int _VK_JUNJA = 0x17;
		const int _VK_FINAL = 0x18;
		const int _VK_HANJA = 0x19;
		const int _VK_KANJI = 0x19;
		const int Escape = 0x1B;
		const int _VK_CONVERT = 0x1C;
		const int _VK_NONCONVERT = 0x1D;
		const int _VK_ACCEPT = 0x1E;
		const int _VK_MODECHANGE = 0x1F;
		const int Space = 0x20;
		const int PageUp = 0x21;
		const int PageDown = 0x22;
		const int End = 0x23;
		const int Home = 0x24;
		const int Left = 0x25;
		const int Up = 0x26;
		const int Right = 0x27;
		const int Down = 0x28;
		const int _VK_SELECT = 0x29;
		const int _VK_PRINT = 0x2A;
		const int _VK_EXECUTE = 0x2B;
		const int PrintScreen = 0x2C;
		const int Insert = 0x2D;
		const int Delete = 0x2E;
		const int _VK_HELP = 0x2F;
		const int Key0 = '0';
		const int Key1 = '1';
		const int Key2 = '2';
		const int Key3 = '3';
		const int Key4 = '4';
		const int Key5 = '5';
		const int Key6 = '6';
		const int Key7 = '7';
		const int Key8 = '8';
		const int Key9 = '9';
		const int KeyA = 'A';
		const int KeyB = 'B';
		const int KeyC = 'C';
		const int KeyD = 'D';
		const int KeyE = 'E';
		const int KeyF = 'F';
		const int KeyG = 'G';
		const int KeyH = 'H';
		const int KeyI = 'I';
		const int KeyJ = 'J';
		const int KeyK = 'K';
		const int KeyL = 'L';
		const int KeyM = 'M';
		const int KeyN = 'N';
		const int KeyO = 'O';
		const int KeyP = 'P';
		const int KeyQ = 'Q';
		const int KeyR = 'R';
		const int KeyS = 'S';
		const int KeyT = 'T';
		const int KeyU = 'U';
		const int KeyV = 'V';
		const int KeyW = 'W';
		const int KeyX = 'X';
		const int KeyY = 'Y';
		const int KeyZ = 'Z';
		const int WinLeft = 0x5B;
		const int WinRight = 0x5C;
		const int Menu = 0x5D;
		const int RightMenu = 0x5D; //same as menu
		const int _VK_SLEEP = 0x5F;
		const int Num0 = 0x60;
		const int Num1 = 0x61;
		const int Num2 = 0x62;
		const int Num3 = 0x63;
		const int Num4 = 0x64;
		const int Num5 = 0x65;
		const int Num6 = 0x66;
		const int Num7 = 0x67;
		const int Num8 = 0x68;
		const int Num9 = 0x69;
		const int NumMultiply = 0x6A;
		const int NumPlus = 0x6B;
		const int _VK_SEPARATOR = 0x6C;
		const int NumMinus = 0x6D;
		const int NumDot = 0x6E;
		const int NumDivide = 0x6F;
		const int F1 = 0x70;
		const int F2 = 0x71;
		const int F3 = 0x72;
		const int F4 = 0x73;
		const int F5 = 0x74;
		const int F6 = 0x75;
		const int F7 = 0x76;
		const int F8 = 0x77;
		const int F9 = 0x78;
		const int F10 = 0x79;
		const int F11 = 0x7A;
		const int F12 = 0x7B;
		const int F13 = 0x7C;
		const int F14 = 0x7D;
		const int F15 = 0x7E;
		const int F16 = 0x7F;
		const int F17 = 0x80;
		const int F18 = 0x81;
		const int F19 = 0x82;
		const int F20 = 0x83;
		const int F21 = 0x84;
		const int F22 = 0x85;
		const int F23 = 0x86;
		const int F24 = 0x87;
		const int Numlock = 0x90;
		const int ScrollLock = 0x91;
		const int _VK_OEM_NEC_EQUAL = 0x92;
		const int _VK_OEM_FJ_JISHO = 0x92;
		const int _VK_OEM_FJ_MASSHOU = 0x93;
		const int _VK_OEM_FJ_TOUROKU = 0x94;
		const int _VK_OEM_FJ_LOYA = 0x95;
		const int _VK_OEM_FJ_ROYA = 0x96;
		const int LeftShift = 0xA0;
		const int RightShift = 0xA1;
		const int LeftControl = 0xA2;
		const int RightControl = 0xA3;
		const int LeftAlt = 0xA4;
		const int RightAlt = 0xA5;
		const int _VK_BROWSER_BACK = 0xA6;
		const int _VK_BROWSER_FORWARD = 0xA7;
		const int _VK_BROWSER_REFRESH = 0xA8;
		const int _VK_BROWSER_STOP = 0xA9;
		const int _VK_BROWSER_SEARCH = 0xAA;
		const int _VK_BROWSER_FAVORITES = 0xAB;
		const int _VK_BROWSER_HOME = 0xAC;
		const int _VK_VOLUME_MUTE = 0xAD;
		const int _VK_VOLUME_DOWN = 0xAE;
		const int _VK_VOLUME_UP = 0xAF;
		const int _VK_MEDIA_NEXT_TRACK = 0xB0;
		const int _VK_MEDIA_PREV_TRACK = 0xB1;
		const int _VK_MEDIA_STOP = 0xB2;
		const int _VK_MEDIA_PLAY_PAUSE = 0xB3;
		const int _VK_LAUNCH_MAIL = 0xB4;
		const int _VK_LAUNCH_MEDIA_SELECT = 0xB5;
		const int _VK_LAUNCH_APP1 = 0xB6;
		const int _VK_LAUNCH_APP2 = 0xB7;
		const int Semicolon = 0xBA;
		const int Plus = 0xBB;
		const int Equals = 0xBB; //same as Plus
		const int Comma = 0xBC;
		const int Minus = 0xBD;
		const int Period = 0xBE;
		const int Slash = 0xBF;
		const int Tilde = 0xC0;
		const int LeftBracket = 0xDB;
		const int BackSlash = 0xDC;
		const int RightBracket = 0xDD;
		const int Apostrophe = 0xDE;
		const int _VK_OEM_8 = 0xDF;
		const int _VK_OEM_AX = 0xE1;
		const int _VK_OEM_102 = 0xE2;
		const int _VK_ICO_HELP = 0xE3;
		const int _VK_ICO_00 = 0xE4;
		const int _VK_PROCESSKEY = 0xE5;
		const int _VK_ICO_CLEAR = 0xE6;
		const int _VK_PACKET = 0xE7;
		const int _VK_OEM_RESET = 0xE9;
		const int _VK_OEM_JUMP = 0xEA;
		const int _VK_OEM_PA1 = 0xEB;
		const int _VK_OEM_PA2 = 0xEC;
		const int _VK_OEM_PA3 = 0xED;
		const int _VK_OEM_WSCTRL = 0xEE;
		const int _VK_OEM_CUSEL = 0xEF;
		const int _VK_OEM_ATTN = 0xF0;
		const int _VK_OEM_FINISH = 0xF1;
		const int _VK_OEM_COPY = 0xF2;
		const int _VK_OEM_AUTO = 0xF3;
		const int _VK_OEM_ENLW = 0xF4;
		const int _VK_OEM_BACKTAB = 0xF5;
		const int _VK_ATTN = 0xF6;
		const int _VK_CRSEL = 0xF7;
		const int _VK_EXSEL = 0xF8;
		const int _VK_EREOF = 0xF9;
		const int _VK_PLAY = 0xFA;
		const int _VK_ZOOM = 0xFB;
		const int _VK_NONAME = 0xFC;
		const int _VK_PA1 = 0xFD;
		const int _VK_OEM_CLEAR = 0xFE;
	};

	struct CButton
	{
		const int Up = 1;
		const int Down = 2;
		const int Left = 4;
		const int Right = 8;
		const int Start = 16;
		const int Back = 32;
		const int LeftStick = 64;
		const int RightStick = 128;
		const int LB = 256;
		const int RB = 512;
		const int _1024 = 1024;
		const int _2048 = 2048;
		const int A = 4096;
		const int B = 8192;
		const int X = 16384;
		const int Y = 32768;
	};
}