#include "PlayGroundLayer.h"

PlayGroundLayer::PlayGroundLayer(){

}

PlayGroundLayer::~PlayGroundLayer(){
    delete m_shader;
	delete m_textShader;
    glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ibo);

}


void PlayGroundLayer::onAttach(){
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_shader = new Shader("PlayGround/Assets/glsl/mainShader.glsl");
	//m_textShader = new Shader("PlayGround/Assets/glsl/textShader.glsl");

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

	uint32_t indices[] = {
         0, 1, 2,
         2, 3, 0 
    };

	glGenBuffers(1, &m_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//m_textRenderer = new TextRenderer(m_textShader, 1080, 720);
	//m_textRenderer->loadFont("PlayGround/Assets/fonts/OCRAEXT.TTF", 24);
}

void PlayGroundLayer::onDetach(){

}

void PlayGroundLayer::onUpdate(float dt, GLFWwindow* win){
    glClearColor(0.25f, 0.25f, 0.25f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//m_frameRate.str("");
	//m_frameRate << ImGui::GetIO().Framerate << " FPS";


};

void PlayGroundLayer::onRender(){
    glUseProgram(m_shader->getId());
    glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	//m_textRenderer->render(m_frameRate.str(), {0.0f, 15.0f}, 0.5f, {0.0f, 1.0f, 0.0f}, false);
}

void PlayGroundLayer::onRenderImgui(){
    ImGui::Begin("Main Window");
    ImGui::End();
}