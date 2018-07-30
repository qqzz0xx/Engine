#pragma once
#include "glad/glad.h"

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

namespace ZZ 
{
	class Shader
	{
	public:
		Shader();
		~Shader();

		void LoadByFile(const std::string& vs, const std::string& fs);
		void Use();
	private:
		GLuint m_ProgramID;
	};

}