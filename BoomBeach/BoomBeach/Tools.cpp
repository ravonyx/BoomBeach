#include "Tools.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint createTexture(const char* name)
{
	int w, h, comp;
	int req_comp = 4;

	auto* image = stbi_load(name, &w, &h, &comp, req_comp);
	if (!image)
	{
		fprintf(stderr, "ERROR: could not load %s\n", name);
		return -1;
	}
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(image);

	return texture;
}
