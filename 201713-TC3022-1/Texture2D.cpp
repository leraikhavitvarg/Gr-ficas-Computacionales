#include "Texture2D.h"
#include <IL/il.h>


Texture2D::Texture2D()
{
	_textureId = 0;

}


Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_textureId);
}


void Texture2D::LoadTexture(std::string path) {
	ILuint imageID;

	ilGenImages(1, &imageID);
	ilBindImage(imageID);
	if (ilLoadImage(path.c_str()))
		std::cout << "no se pudo cargar " << path << std::endl;

	glGenTextures(1, &_textureId);
	glBindTexture(GL_TEXTURE_2D, _textureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//aqui va
	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_FORMAT),
		ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
		0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_TYPE),
		ilGetData());


	//apagamos
	glBindTexture(GL_TEXTURE_2D, 0);


	ilBindImage(0);
	ilDeleteImages(1, &imageID);

}
void Texture2D::Bind() {
	glBindTexture(GL_TEXTURE_2D, _textureId);
}
void Texture2D::Unbind() {

	glBindTexture(GL_TEXTURE_2D, 0);
}