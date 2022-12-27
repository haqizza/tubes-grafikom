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



GLfloat verticesBuildings[] = {
	//1
	 //ALAS
	-0.35f, -0.40f,  0.35f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	 0.35f, -0.40f,  0.35f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	 0.35f, -0.40f, -0.35f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	-0.35f, -0.40f, -0.35f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 0.0f,  0.0f,

	//ATAP
   -0.35f, 0.6f,  0.35f,		0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
	0.35f, 0.6f,  0.35f,		0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 0.0f,  0.1f,
	0.35f, 0.6f, -0.35f,		0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
   -0.35f, 0.6f, -0.35f,		0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 0.0f,  0.0f,

   //2
   //ALAS
   -0.25f, 0.6f,  0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	0.25f, 0.6f,  0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.0f,		0.0f, 0.0f,  0.1f,
	0.25f, 0.6f, -0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
   -0.25f, 0.6f, -0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.0f,		0.0f, 0.0f,  0.0f,

   //ATAP
   -0.25f, 1.1f,  0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.5f,		0.0f, 0.0f,  0.0f,
	0.25f, 1.1f,  0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.5f,		0.0f, 0.0f,  0.1f,
	0.25f, 1.1f, -0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.5f,		0.0f, 0.0f,  0.0f,
   -0.25f, 1.1f, -0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.5f,		0.0f, 0.0f,  0.0f,

   //3
   //ATAP
	-0.10f, 1.35f,  0.10f,		0.83f, 0.70f, 0.44f,	0.0f, 0.5f,		0.8f, 0.5f,  0.8f,
	 0.10f, 1.35f,  0.10f,		0.83f, 0.70f, 0.44f,	0.5f, 0.5f,		0.8f, 0.5f,  0.8f,
	 0.10f, 1.35f, -0.10f,		0.83f, 0.70f, 0.44f,	0.0f, 0.5f,		0.8f, 0.5f,  0.8f,
	-0.10f, 1.35f, -0.10f,		0.83f, 0.70f, 0.44f,	0.5f, 0.5f,		0.8f, 0.5f,  0.8f
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

	16, 17, 19,
	17, 18, 19
};


GLfloat verticesPlain[] = {
	-1.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	-0.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	-0.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 9.0f,		0.0f, 0.0f,  0.0f,
	-1.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 9.0f,		0.0f, 0.0f,  0.1f,
			
	 0.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	 1.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	 1.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 9.0f,		0.0f, 0.0f,  0.0f,
	 0.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 9.0f,		0.0f, 0.0f,  0.1f
};

GLuint indicesPlain[] = {
	0, 1, 3,
	1, 2, 3,

	4, 5, 7,
	5, 6, 7
};


GLfloat verticesLand[] = {
	-1.55f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		0.0f, 0.0f,		0.0f, 0.0f,  0.0f, 
	 1.55f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		3.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	 1.55f, -0.40f, -0.55f,     0.83f, 0.10f, 0.64f,		0.0f, 3.0f,		0.0f, 0.0f,  0.0f,
	-1.55f, -0.40f, -0.55f,     0.83f, 0.10f, 0.64f,		3.0f, 3.0f,		0.0f, 0.0f, -0.025f
};

GLuint indicesLand[] = {
	0, 1, 3,
	1, 2, 3
};


GLfloat verticesRoad[] = {
	-1.55f, -0.40f,  1.00f,     0.83f, 0.10f, 0.64f,		0.0f, 0.0f,		 0.0f, 0.5f,  0.3f,
	 1.55f, -0.40f,  1.00f,     0.83f, 0.10f, 0.64f,		3.0f, 0.0f,		 0.0f, 0.5f,  0.4f,
	 1.55f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		0.0f, 3.0f,		 0.0f, 0.5f,  0.4f,
	-1.55f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		3.0f, 3.0f,		 0.0f, 0.5f,  0.4f
};

GLuint indicesRoad[] = {
	0, 1, 3,
	1, 2, 3
};


GLfloat verticesRoof[] = {
   -0.17f, 1.1f,  0.17f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	0.17f, 1.1f,  0.17f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	0.17f, 1.1f, -0.17f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
   -0.17f, 1.1f, -0.17f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 0.0f,  0.0f,

   -0.10f, 1.35f,  0.10f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
	0.10f, 1.35f,  0.10f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 0.0f,  0.1f,
	0.10f, 1.35f, -0.10f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
   -0.10f, 1.35f, -0.10f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 0.0f,  0.0f

};

GLuint indicesRoof[] = {
	0, 1, 4,
	0, 3, 4,
	1, 4, 5,
	1, 2, 5,
	2, 5, 6,
	2, 3, 6,
	3, 6, 7,
	3, 4, 7

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


	Shader buildingShader("vertexShader.vert", "fragmentShader.frag");

	VAO VAOBuildings;
	VAOBuildings.Bind();

	VBO VBOBuildings(verticesBuildings, sizeof(verticesBuildings));
	EBO EBOBuildings(indicesBuildings, sizeof(indicesBuildings));
	
	//Link all attribute
	VAOBuildings.LinkAttribAll(VBOBuildings);
	
	VAOBuildings.Unbind();
	VBOBuildings.Unbind();
	EBOBuildings.Unbind();



	//land shader
	Shader plainShader("vertexShader.vert", "fragmentShader.frag");
	
	VAO VAOPlain;
	VAOPlain.Bind();
	
	VBO VBOPlain(verticesPlain, sizeof(verticesPlain));
	
	EBO EBOPlain(indicesPlain, sizeof(indicesPlain));
	
	VAOPlain.LinkAttribAll(VBOPlain);

	VAOPlain.Unbind();
	VBOPlain.Unbind();
	EBOPlain.Unbind();



	//Building land shader
	Shader landShader("vertexShader.vert", "fragmentShader.frag");

	VAO VAOLand;
	VAOLand.Bind();

	VBO VBOLand(verticesLand, sizeof(verticesLand));
	EBO EBOLand(indicesLand, sizeof(indicesLand));

	VAOLand.LinkAttribAll(VBOLand);

	VAOLand.Unbind();
	VBOLand.Unbind();
	EBOLand.Unbind();



	//Road Shader
	Shader roadShader("vertexShader.vert", "fragmentShader.frag");

	VAO VAORoad;
	VAORoad.Bind();

	VBO VBORoad(verticesRoad, sizeof(verticesRoad));
	EBO EBORoad(indicesRoad, sizeof(indicesRoad));
	
	VAORoad.LinkAttribAll(VBORoad);
	
	VAORoad.Unbind();
	VBORoad.Unbind();
	EBORoad.Unbind();



	//Roof shader
	Shader roofShader("vertexShader.vert", "fragmentShader.frag");
	
	VAO VAORoof;
	VAORoof.Bind();
	
	VBO VBORoof(verticesRoof, sizeof(verticesRoof));
	EBO EBORoof(indicesRoof, sizeof(indicesRoof));
	
	VAORoof.LinkAttribAll(VBORoof);
	
	VAORoof.Unbind();
	VBORoof.Unbind();
	EBORoof.Unbind();



	// Light shader
	Shader lightShader("light.vert", "light.frag");
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
	Texture brickTex("img/skyscrap.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	Texture grassTex("img/grass.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE); //Photo by pixmike from Pexels
	Texture landTex("img/land3.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	Texture roadTex("img/road.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	Texture roofTex("img/glass.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);

	brickTex.texUnit(plainShader, "tex0", 0);
	grassTex.texUnit(buildingShader, "tex0", 0);
	landTex.texUnit(landShader, "stbtex0", 0);
	roadTex.texUnit(roadShader, "tex0", 0);
	roofTex.texUnit(roofShader, "tex0", 0);
	


	//Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Create camera object
	Camera camera(width, height, glm::vec3(0.0f, 2.0f, 1.5f));


	// glm::vec3 testPos = glm::vec3(-1.0f, -1.0f, 0.0f);
	// glm::mat4 testModel = glm::mat4(1.0f);
	// testModel = glm::translate(testModel, testPos);

	// glm::vec3 translationA(0.0f, 0.0f, 0.0f);
	// glm::vec3 translationB(0.5f, 0.0f, 0.2f);

	while (!glfwWindowShouldClose(window))
	{
		// background color
		glClearColor(0.53f, 0.81f, 0.92f, 0.8f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// set build models
		std::list<glm::mat4> modelList;

		// generate buildings position
		for (int posX = 0; posX <= (3 * 10); posX = posX + 3){
			for (int posZ = 0; posZ <= (2 * 5); posZ = posZ + 2){
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


		//print objects
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
			
			roofShader.Activate();
			glUniformMatrix4fv(glGetUniformLocation(roofShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(*model));
			glUniform4f(glGetUniformLocation(roofShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform3f(glGetUniformLocation(roofShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);



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


			//draw roof
			roofShader.Activate();
			glUniform3f(glGetUniformLocation(roofShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
			
			camera.Matrix(roofShader, "camMatrix");
			
			roofTex.Bind();
			VAORoof.Bind();
			glDrawElements(GL_TRIANGLES, sizeof(indicesRoof) / sizeof(int), GL_UNSIGNED_INT, 0);

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


		//draw light
		lightShader.Activate();
		
		camera.Matrix(lightShader, "camMatrix");
		
		lightVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);


		// const float radius = 3.0f;
		// float camX = sin(glfwGetTime()) * radius;
		// float camY = cos(glfwGetTime()) * radius;
		// glm::mat4 transform = glm::mat4(1.0f);
        // buildModel = glm::translate(buildModel, translationA);
		// unsigned int transformLoc = glGetUniformLocation(buildingShader.ID, "aUniform");
        // lightModel = glm::rotate(lightModel, (float)glfwGetTime(), glm::vec3(camX, camY, 1.0f));
		// glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(lightModel));

		// glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(buildModel));
        

		// glDrawElements(GL_TRIANGLES, sizeof(indicesBuildings) / sizeof(int), GL_UNSIGNED_INT, 0);



		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	VAOBuildings.Delete();
	VBOBuildings.Delete();
	EBOBuildings.Delete();
	buildingShader.Delete();
	VAOPlain.Delete();
	VBOPlain.Delete();
	EBOPlain.Delete();
	plainShader.Delete();
	VAOLand.Delete();
	VBOLand.Delete();
	EBOLand.Delete();
	landShader.Delete();
	VAORoad.Delete();
	VBORoad.Delete();
	EBORoad.Delete();
	roadShader.Delete();
	VAORoof.Delete();
	VBORoof.Delete();
	EBORoof.Delete();
	roofShader.Delete();
	brickTex.Delete();
	grassTex.Delete();
	landTex.Delete();
	roadTex.Delete();
	roofTex.Delete();
	lightVAO.Delete();
	lightVBO.Delete();
	lightEBO.Delete();
	lightShader.Delete();
	
	glfwDestroyWindow(window);
	
	glfwTerminate();
	return 0;
}