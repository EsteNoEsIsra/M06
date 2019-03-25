#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <map>

std::string* textures;

int LoadTextures(std::ifstream &archivo,int numeroDeTexturas)
{
	std::string word;
	textures = new std::string[numeroDeTexturas + 1];
	textures[0] = "none";

	int counter = 1;
	while (counter < numeroDeTexturas+1 )
	{
		std::getline(archivo, word, ';');
		std::getline(archivo, word, ';');

		std::cout << word << '\n';
		std::getline(archivo, word, '\n');

		counter++;
	}
	return 0;
}


int main(int argc,char* argv[])
{
	
	std::ifstream file_conf("../RafaUF1/game.csv");
	if (!file_conf.is_open())
	{
		std::cout << "ERROR: Game no pudo abirise" << "\n";
		return 1;
	}
	std::string word;
	std::string title;
	int textureNum = 0;




	while (file_conf.good())
	{
		std::getline(file_conf, word, ';');


		if (word.compare("TEXTURES") == 0)
		{
			std::getline(file_conf, word, ';');
			textureNum = std::stoi(word);
			std::getline(file_conf, word, '\n');

			LoadTextures(file_conf,textureNum);

		}
		else if (word.compare("TITLE")== 0)
		{
			std::getline(file_conf, title, ';');
			std::getline(file_conf, word, '\n');
		}


	

	}

	file_conf.close();
}


























//int main(int argc,char* argv[])
	//{

	// prueba nazzi 
	/*
	std::ofstream archivo;

	archivo.open("datos.csv");

	archivo << "a;b;c;\n";
	archivo << "d;e;f;\n";
	archivo << "1;2;3.456;\n";
	archivo.close();

	return 0;
	*/
	/*
	std::ifstream ip("../RafaUF1/personas.csv");
	if (!ip.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << "\n";
		return 1;
	}


	std::string nombre;
	std::string apellido;
	std::string edad;
	std::string peso;

	int edadI = 0;
	float pesoF = 0.f;


	while (ip.good())
	{
		std::getline(ip, nombre, ';');
		std::getline(ip, apellido, ';');
		std::getline(ip, edad, ';');
		std::getline(ip, peso, '\n');


		edadI = std::stoi(edad);
		pesoF = std::stof(peso);



		std::cout << "Nombre: " << nombre << " " << apellido << std::endl;
		std::cout << "Edad: " << edad << std::endl;
		std::cout << "Peso: " << peso << std::endl;
		std::cout << "___________________" << std::endl;

	}

	ip.close();
	}

	*/

