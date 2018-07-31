#include "Shader.h"

using namespace ZZ;
using namespace std;
Shader::Shader()
{
}

Shader::~Shader()
{
}

void Shader::LoadByFile(const std::string & vs, const std::string & fs)
{
	GLint ok;
	GLchar infoLog[512];

	auto readFileFunc = [&](const std::string &  vs)
	{
		try
		{
			ifstream ifs;
			stringstream ss;
			ifs.open(vs);
			ss << ifs.rdbuf();
			ifs.close();
			return ss.str();
		}
		catch (exception& ex)
		{
			cout << ex.what() << endl;
		}

		return string();
	};
	auto compileShaderFunc = [&](const std::string &  vs_txt, auto type)
	{
		const GLchar * p_vs_txt = vs_txt.c_str();
		auto vs_id = glCreateShader(type);
		glShaderSource(vs_id, 1, &p_vs_txt, nullptr);
		glCompileShader(vs_id);
		glGetShaderiv(vs_id, GL_COMPILE_STATUS, &ok);

		if (!ok)
		{
			glGetShaderInfoLog(vs_id, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		return vs_id;
	};

	auto vs_id = compileShaderFunc(readFileFunc(vs), GL_VERTEX_SHADER);
	auto fs_id = compileShaderFunc(readFileFunc(fs), GL_FRAGMENT_SHADER);

	// Shader Program
	this->ID = glCreateProgram();
	glAttachShader(this->ID, vs_id);
	glAttachShader(this->ID, fs_id);
	glLinkProgram(this->ID);
	// Print linking errors if any
	glGetProgramiv(this->ID, GL_LINK_STATUS, &ok);
	if (!ok)
	{
		glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vs_id);
	glDeleteShader(fs_id);
}




