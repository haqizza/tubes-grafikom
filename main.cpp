#include <iostream>
#include <stdio.h>
#include <list>

#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"

#include "include/glm/glm.hpp"
#include "include/glm/gtc/matrix_transform.hpp"
#include "include/glm/gtc/type_ptr.hpp"

// #define STB_IMAGE_IMPLEMENTATION
#include "include/stb/stb_image.h"

#include "Texture.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Camera.h"

const unsigned int width = 1366;
const unsigned int height = 768;


GLfloat verticesBuildings2[] = 
{
	//bangunan
	-0.35f, -0.40f, -0.15f,     0.83f, 0.70f, 0.44f,	0.3f, 0.0f,		0.0f, 0.0f,  0.0f,
	-0.35f, -0.40f,  0.15f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,//L

	-0.15f, -0.40f,  0.35f,     0.83f, 0.70f, 0.44f,	0.3f, 0.0f,		0.0f, 0.0f,  0.1f,
	 0.15f, -0.40f,  0.35f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.1f,//T
	
	 0.35f, -0.40f,  0.15f,     0.83f, 0.70f, 0.44f,	0.3f, 0.0f,		0.0f, 0.0f,  0.0f,//R
	 0.35f, -0.40f, -0.15f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	
	 0.15f, -0.40f, -0.35f,     0.83f, 0.70f, 0.44f,	0.3f, 0.0f,		0.0f, 0.0f,  0.0f,//B
	-0.15f, -0.40f, -0.35f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,

	//atap
	-0.35f, 1.3f, -0.15f,     0.83f, 0.70f, 0.44f,	0.3f, 1.0f,		0.0f, 0.0f,  0.0f,
	-0.35f, 1.3f,  0.15f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,//L
	-0.15f, 1.3f,  0.35f,     0.83f, 0.70f, 0.44f,	0.3f, 1.0f,		0.0f, 0.0f,  0.1f,
	 0.15f, 1.3f,  0.35f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.1f,//T
	 0.35f, 1.3f,  0.15f,     0.83f, 0.70f, 0.44f,	0.3f, 1.0f,		0.0f, 0.0f,  0.0f,//R
	 0.35f, 1.3f, -0.15f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
	 0.15f, 1.3f, -0.35f,     0.83f, 0.70f, 0.44f,	0.3f, 1.0f,		0.0f, 0.0f,  0.0f,//B
	-0.15f, 1.3f, -0.35f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
};

GLuint indicesBuildings2[] =
{
	0, 1, 8,
	1, 8, 9,
	1, 2, 9,
	2, 9, 10,
	2, 3, 10,
	3, 10, 11,
	3, 4, 11,
	4, 11, 12,
	4, 5, 12,
	5, 12, 13,
	5, 6, 13,
	6, 13, 14,
	6, 7, 14,
	7, 14, 15,
	7, 0, 15,
	0, 15, 8,

	8, 9, 10,
	10, 11, 12,
	12, 13, 14,
	14, 15, 8,
	8, 10, 14,
	10, 12, 14
};

GLfloat verticesBuildings[] = 
{
	//1
	 //bangunan
	-0.35f, -0.40f,  0.35f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	 0.35f, -0.40f,  0.35f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	 0.35f, -0.40f, -0.35f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	-0.35f, -0.40f, -0.35f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 0.0f,  0.0f,

	//atap
   -0.35f, 0.6f,  0.35f,		0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
	0.35f, 0.6f,  0.35f,		0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 0.0f,  0.1f,
	0.35f, 0.6f, -0.35f,		0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
   -0.35f, 0.6f, -0.35f,		0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 0.0f,  0.0f,

   //2
   //bangunan
   -0.25f, 0.6f,  0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	0.25f, 0.6f,  0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.0f,		0.0f, 0.0f,  0.1f,
	0.25f, 0.6f, -0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
   -0.25f, 0.6f, -0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.0f,		0.0f, 0.0f,  0.0f,

   //atap
   -0.25f, 1.1f,  0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.5f,		0.0f, 0.0f,  0.0f,
	0.25f, 1.1f,  0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.5f,		0.0f, 0.0f,  0.1f,
	0.25f, 1.1f, -0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.5f,		0.0f, 0.0f,  0.0f,
   -0.25f, 1.1f, -0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.5f,		0.0f, 0.0f,  0.0f,
};

// Indices for vertices order
GLuint indicesBuildings[] =
{
	0, 1, 4,
	0, 3, 4,
	1, 4, 5,
	1, 2, 5,
	2, 5, 6,
	2, 3, 6,
	3, 6, 7,
	3, 4, 7,
	4, 5, 7,
	5, 6, 7,

	8, 9, 12,
	8, 11, 12,
	9, 12, 13,
	9, 10, 13,
	10, 13, 14,
	10, 11, 14,
	11, 14, 15,
	11, 12, 15,
	12, 13, 15,
	13, 14, 15,
};


GLfloat verticesPlain[] = 
{
	-1.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	-0.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	-0.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 9.0f,		0.0f, 0.0f,  0.0f,
	-1.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 9.0f,		0.0f, 0.0f,  0.1f,
			
	 0.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	 1.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	 1.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 9.0f,		0.0f, 0.0f,  0.0f,
	 0.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 9.0f,		0.0f, 0.0f,  0.1f
};

GLuint indicesPlain[] = 
{
	0, 1, 3,
	1, 2, 3,

	4, 5, 7,
	5, 6, 7
};


GLfloat verticesLand[] = 
{
	-1.50f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		0.0f, 0.0f,		0.0f, 0.0f,  0.0f, 
	 1.50f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		3.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	 1.50f, -0.40f, -0.55f,     0.83f, 0.10f, 0.64f,		0.0f, 3.0f,		0.0f, 0.0f,  0.0f,
	-1.50f, -0.40f, -0.55f,     0.83f, 0.10f, 0.64f,		3.0f, 3.0f,		0.0f, 0.0f, -0.025f
};

GLuint indicesLand[] = 
{
	0, 1, 3,
	1, 2, 3
};

GLfloat verticesFlyingObject[] = 
{
	-0.8f, 2.0f, -0.6f,     0.83f, 0.10f, 0.64f,		0.0f, 0.0f,		 0.0f, 0.5f,  0.3f,
	-0.8f, 2.0f,  0.6f,     0.83f, 0.10f, 0.64f,		1.0f, 0.0f,		 0.0f, 0.5f,  0.4f,
	 0.8f, 2.0f,  0.6f,     0.83f, 0.10f, 0.64f,		1.0f, 1.0f,		 0.0f, 0.5f,  0.4f,
	 0.8f, 2.0f, -0.6f,     0.83f, 0.10f, 0.64f,		0.0f, 1.0f,		 0.0f, 0.5f,  0.4f
};

GLuint indicesFlyingObject[] = 
{
	0, 1, 3,
	1, 2, 3
};

GLfloat verticesRoad[] = 
{
	-1.55f, -0.40f,  1.00f,     0.83f, 0.10f, 0.64f,		0.0f, 1.0f,		 0.0f, 0.5f,  0.3f,
	 1.55f, -0.40f,  1.00f,     0.83f, 0.10f, 0.64f,		1.0f, 1.0f,		 0.0f, 0.5f,  0.4f,
	 1.55f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		1.0f, 0.0f,		 0.0f, 0.5f,  0.4f,
	-1.55f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		0.0f, 0.0f,		 0.0f, 0.5f,  0.4f
};

GLuint indicesRoad[] = {
	0, 1, 3,
	1, 2, 3
};


GLfloat lightVertices[] = {
	 1.3f,  1.5f,  1.1f,
	 1.3f,  1.5f,  1.0f,
	 1.5f,  1.5f,  1.0f,
	 1.5f,  1.5f,  1.1f,
	 1.3f,  1.4f,  1.1f,
	 1.3f,  1.4f,  1.0f,
	 1.5f,  1.4f,  1.0f,
	 1.5f,  1.4f,  1.1f
};

GLuint lightIndices[] = {
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};


int main()
{
	// Initialize GLFW
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, "Building", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);

	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	
	glViewport(0, 0, width, height);


	//building shader
	Shader buildingShader("vertexShader.vs", "fragmentShader.fs");

	VAO VAOBuildings;
	VAOBuildings.Bind();

	VBO VBOBuildings(verticesBuildings, sizeof(verticesBuildings));
	EBO EBOBuildings(indicesBuildings, sizeof(indicesBuildings));
	
	//Link all attribute
	VAOBuildings.LinkAttribAll(VBOBuildings);
	
	VAOBuildings.Unbind();
	VBOBuildings.Unbind();
	EBOBuildings.Unbind();


	//building2 shader
	Shader building2Shader("vertexShader.vs", "fragmentShader.fs");

	VAO VAOBuildings2;
	VAOBuildings2.Bind();

	VBO VBOBuildings2(verticesBuildings2, sizeof(verticesBuildings2));
	EBO EBOBuildings2(indicesBuildings2, sizeof(indicesBuildings2));
	
	//Link all attribute
	VAOBuildings2.LinkAttribAll(VBOBuildings2);
	
	VAOBuildings2.Unbind();
	VBOBuildings2.Unbind();
	EBOBuildings2.Unbind();



	//land shader
	Shader plainShader("vertexShader.vs", "fragmentShader.fs");
	
	VAO VAOPlain;
	VAOPlain.Bind();
	
	VBO VBOPlain(verticesPlain, sizeof(verticesPlain));
	
	EBO EBOPlain(indicesPlain, sizeof(indicesPlain));
	
	VAOPlain.LinkAttribAll(VBOPlain);

	VAOPlain.Unbind();
	VBOPlain.Unbind();
	EBOPlain.Unbind();



	//Building land shader
	Shader landShader("vertexShader.vs", "fragmentShader.fs");

	VAO VAOLand;
	VAOLand.Bind();

	VBO VBOLand(verticesLand, sizeof(verticesLand));
	EBO EBOLand(indicesLand, sizeof(indicesLand));

	VAOLand.LinkAttribAll(VBOLand);

	VAOLand.Unbind();
	VBOLand.Unbind();
	EBOLand.Unbind();


	//Flying object shader
	Shader flyingShader("flyingObject.vs", "flyingObject.fs");

	VAO VAOFly;
	VAOFly.Bind();

	VBO VBOFly(verticesFlyingObject, sizeof(verticesFlyingObject));
	EBO EBOFly(indicesFlyingObject, sizeof(indicesFlyingObject));

	VAOFly.LinkAttribAll(VBOFly);

	VAOFly.Unbind();
	VBOFly.Unbind();
	EBOFly.Unbind();



	//Road Shader
	Shader roadShader("vertexShader.vs", "fragmentShader.fs");

	VAO VAORoad;
	VAORoad.Bind();

	VBO VBORoad(verticesRoad, sizeof(verticesRoad));
	EBO EBORoad(indicesRoad, sizeof(indicesRoad));
	
	VAORoad.LinkAttribAll(VBORoad);
	
	VAORoad.Unbind();
	VBORoad.Unbind();
	EBORoad.Unbind();



	// Light shader
	Shader lightShader("light.vs", "light.fs");
	VAO lightVAO;
	lightVAO.Bind();
	
	VBO lightVBO(lightVertices, sizeof(lightVertices));
	EBO lightEBO(lightIndices, sizeof(lightIndices));
	
	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	
	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();

	//set light model
	glm::vec4 lightColor = glm::vec4(2.0f, 2.0f, 2.0f, 2.0f);
	glm::vec3 lightPos = glm::vec3(0.0f, 5.0f, 1.0f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);


	//Load textures
	Texture brickTex("img/skyscraper1.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE);
	Texture wallTex("img/skyscraper2.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE);
	Texture grassTex("img/grass.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE); //Photo by pixmike from Pexels
	Texture landTex("img/land.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE);
	Texture roadTex("img/road.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE);
	Texture planeTex("img/plane1.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_RGBA, GL_UNSIGNED_BYTE);

	grassTex.texUnit(plainShader, "tex0", 0);
	brickTex.texUnit(buildingShader, "tex0", 0);
	wallTex.texUnit(building2Shader, "tex0", 0);
	landTex.texUnit(landShader, "stbtex0", 0);
	roadTex.texUnit(roadShader, "tex0", 0);
	planeTex.texUnit(flyingShader, "tex0", 0);


	//Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Create camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.05f, 1.5f));



	// set build models
	std::list<glm::mat4> modelList;
	std::list<glm::mat4> modelList2;
	
	int posX = 0;
	int posZ = 0;
	
	// generate objects position
	for (posX = 0; posX <= (3 * 10); posX = posX + 6){
		for (posZ = 0; posZ <= (2 * 5); posZ = posZ + 2){
			glm::mat4 buildModel = glm::mat4(1.0f);
			buildModel = glm::translate(buildModel, glm::vec3(posX * 1.0f, -0.0f, posZ * 1.0f));
			modelList.push_back(buildModel);

			//side 2
			glm::mat4 buildModel2 = glm::mat4(1.0f);
			buildModel2 = glm::translate(buildModel2, glm::vec3(posX * 1.0f, 0.0f, posZ * 1.0f));
			buildModel2 = glm::rotate(buildModel2, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			modelList.push_back(buildModel2);
		}
	};

	for (posX = 3; posX <= (3 * 10); posX = posX + 6){
		for (posZ = 0; posZ <= (2 * 5); posZ = posZ + 2){
			glm::mat4 buildModel = glm::mat4(1.0f);
			buildModel = glm::translate(buildModel, glm::vec3(posX * 1.0f, -0.0f, posZ * 1.0f));
			modelList2.push_back(buildModel);

			//side 2
			glm::mat4 buildModel2 = glm::mat4(1.0f);
			buildModel2 = glm::translate(buildModel2, glm::vec3(posX * 1.0f, 0.0f, posZ * 1.0f));
			buildModel2 = glm::rotate(buildModel2, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			modelList2.push_back(buildModel2);
		}
	};


	while (!glfwWindowShouldClose(window))
	{
		// background color
		glClearColor(0.53f, 0.81f, 0.92f, 0.8f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		//draw objects
		std::list<glm::mat4>::iterator model;


    	for (model = modelList.begin(); model != modelList.end(); ++model){
			//set uniform model
			lightShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
			glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

			plainShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(plainShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(*model));
			glUniform4f(glGetUniformLocation(plainShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(plainShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

			buildingShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(buildingShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(*model));
			glUniform4f(glGetUniformLocation(buildingShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(buildingShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

			landShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(landShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(*model));
			glUniform4f(glGetUniformLocation(landShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(landShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

			roadShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(roadShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(*model));
			glUniform4f(glGetUniformLocation(roadShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(roadShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
			
			// Handles camera inputs
			camera.Inputs(window);
			// Updates and exports the camera matrix to the Vertex Shader
			camera.updateMatrix(30.0f, 0.1f, 100.0f);

			//draw land
			landShader.Activate();
			glUniform3f(glGetUniformLocation(landShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
			
			camera.Matrix(landShader, "camMatrix");
			
			landTex.Bind();
			VAOLand.Bind();
			glDrawElements(GL_TRIANGLES, sizeof(indicesLand) / sizeof(int), GL_UNSIGNED_INT, 0);


			// draw road
			roadShader.Activate();
			
			glUniform3f(glGetUniformLocation(roadShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
			
			camera.Matrix(roadShader, "camMatrix");
			
			roadTex.Bind();
			VAORoad.Bind();
			glDrawElements(GL_TRIANGLES, sizeof(indicesRoad) / sizeof(int), GL_UNSIGNED_INT, 0);


			//draw building
			buildingShader.Activate();
			glUniform3f(glGetUniformLocation(buildingShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
			
			// Set camera
			//Export the camMatrix to the Shader
			camera.Matrix(buildingShader, "camMatrix");
			
			brickTex.Bind();
			VAOBuildings.Bind();

			glDrawElements(GL_TRIANGLES, sizeof(indicesBuildings) / sizeof(int), GL_UNSIGNED_INT, 0);
		}

		// draw object 2nd
    	for (model = modelList2.begin(); model != modelList2.end(); ++model){
			//set uniform model
			lightShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
			glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

			plainShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(plainShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(*model));
			glUniform4f(glGetUniformLocation(plainShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(plainShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

			building2Shader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(building2Shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(*model));
			glUniform4f(glGetUniformLocation(building2Shader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(building2Shader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

			landShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(landShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(*model));
			glUniform4f(glGetUniformLocation(landShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(landShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

			roadShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(roadShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(*model));
			glUniform4f(glGetUniformLocation(roadShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(roadShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
			
			// Handles camera inputs
			camera.Inputs(window);
			// Updates and exports the camera matrix to the Vertex Shader
			camera.updateMatrix(30.0f, 0.1f, 100.0f);

			//draw land
			landShader.Activate();
			glUniform3f(glGetUniformLocation(landShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
			
			camera.Matrix(landShader, "camMatrix");
			
			grassTex.Bind();
			VAOLand.Bind();
			glDrawElements(GL_TRIANGLES, sizeof(indicesLand) / sizeof(int), GL_UNSIGNED_INT, 0);


			// draw road
			roadShader.Activate();
			
			glUniform3f(glGetUniformLocation(roadShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
			
			camera.Matrix(roadShader, "camMatrix");
			
			roadTex.Bind();
			VAORoad.Bind();
			glDrawElements(GL_TRIANGLES, sizeof(indicesRoad) / sizeof(int), GL_UNSIGNED_INT, 0);


			//draw building2
			building2Shader.Activate();
			glUniform3f(glGetUniformLocation(building2Shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
			
			camera.Matrix(building2Shader, "camMatrix");
			
			wallTex.Bind();
			VAOBuildings2.Bind();

			glDrawElements(GL_TRIANGLES, sizeof(indicesBuildings2) / sizeof(int), GL_UNSIGNED_INT, 0);
		}


		//draw light
		lightShader.Activate();
		
		camera.Matrix(lightShader, "camMatrix");
		
		lightVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		// camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		// camera.updateMatrix(30.0f, 0.1f, 100.0f);

		//Flying object

		GLfloat delta, last;
		GLfloat timer = glfwGetTime();
		last = timer;
		delta = timer - last;

		const float radius = 20.0f;
		float camX = sin(delta) * radius;
		float camY = cos(delta) * radius;

		glm::mat4 transform = glm::mat4(1.0f);

		transform = glm::translate(transform, glm::vec3(posX / 2 * 1.0f, 0.0f, posZ / 2 * 1.0f));// move object to center of city
        transform = glm::rotate(transform, (float)glfwGetTime()/20, glm::vec3(0.0f, 0.0f, -2.0f));
        transform = glm::translate(transform, glm::vec3(camX, camY, 0.0f));



		flyingShader.Activate();


		glUniformMatrix4fv(glGetUniformLocation(flyingShader.ID, "transform"), 1, GL_FALSE, glm::value_ptr(transform));
		glUniform4f(glGetUniformLocation(flyingShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(flyingShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
		
		
		glUniform3f(glGetUniformLocation(flyingShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		
		camera.Matrix(flyingShader, "camMatrix");
		
		planeTex.Bind();
		VAOFly.Bind();

		glDrawElements(GL_TRIANGLES, sizeof(indicesFlyingObject) / sizeof(int), GL_UNSIGNED_INT, 0);




		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	VAOBuildings.Delete();
	VBOBuildings.Delete();
	EBOBuildings.Delete();
	buildingShader.Delete();
	VAOBuildings2.Delete();
	VBOBuildings2.Delete();
	EBOBuildings2.Delete();
	building2Shader.Delete();
	VAOPlain.Delete();
	VBOPlain.Delete();
	EBOPlain.Delete();
	plainShader.Delete();
	VAOLand.Delete();
	VBOLand.Delete();
	EBOLand.Delete();
	landShader.Delete();
	// flyingShader.Delete();
	// VAOFly.Delete();
	// VBOFly.Delete();
	// EBOFly.Delete();
	VAORoad.Delete();
	VBORoad.Delete();
	EBORoad.Delete();
	roadShader.Delete();
	brickTex.Delete();
	grassTex.Delete();
	landTex.Delete();
	roadTex.Delete();
	lightVAO.Delete();
	lightVBO.Delete();
	lightEBO.Delete();
	lightShader.Delete();
	
	glfwDestroyWindow(window);
	
	glfwTerminate();
	return 0;
}