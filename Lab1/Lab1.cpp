
#include "Graphics.h"

int main( void )
{
	Graphics* graphics = Graphics::GetGraphicsContext();
	if (graphics->CreateGraphicsContext() == -1)
	{
		return -1;
	}

	graphics->Draw();
}

