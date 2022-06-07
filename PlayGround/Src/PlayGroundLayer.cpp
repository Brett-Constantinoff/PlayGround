#include "PlayGroundLayer.h"

PlayGroundLayer::PlayGroundLayer()
{

}

PlayGroundLayer::~PlayGroundLayer()
{
    delete m_shader;
	delete m_textShader;
	delete m_camera;
	delete m_textRenderer;
	delete m_vao;
}

void PlayGroundLayer::onAttach(Window* win)
{
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_window = win;

	m_shader = new Shader("PlayGround/Assets/glsl/mainShader.glsl");
	m_textShader = new Shader("PlayGround/Assets/glsl/textShader.glsl");

	m_camera = new Camera({0.0f, 0.0f, 7.5f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f, 0.0f});

	m_quadColour = {0.34f, 0.57f, 0.89f};

	m_vao = new VertexArray();
	m_vao->bind();

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	VertexBuffer vbo(GL_ARRAY_BUFFER);
	vbo.bind();
	vbo.setData(sizeof(vertices), vertices, GL_STATIC_DRAW);

	m_vao->setAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

	uint32_t indices[] = {
         0, 1, 2,
         2, 3, 0 
    };

	VertexBuffer ibo(GL_ELEMENT_ARRAY_BUFFER);
	ibo.bind();
	ibo.setData(sizeof(indices), indices, GL_STATIC_DRAW);

	m_vao->unBind();

	m_textRenderer = new TextRenderer(m_textShader, m_window->getWidth(), m_window->getWidth());
	m_textRenderer->loadFont("PlayGround/Assets/fonts/OCRAEXT.TTF", 24);
}

void PlayGroundLayer::onDetach()
{

}

void PlayGroundLayer::onUpdate(float dt)
{
	m_camera->move(m_window->getContext(), dt);

	m_projection = glm::perspective(glm::radians(45.0f), static_cast<float>(m_window->getWidth()) / static_cast<float>(m_window->getHeight()), 0.1f, 100.0f);
	m_view = *m_camera->getView();
    glClearColor(0.25f, 0.25f, 0.25f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_frameRate.str("");
	m_frameRate << ImGui::GetIO().Framerate << " FPS";
};

void PlayGroundLayer::onRender()
{
	glUseProgram(m_shader->getId());

	m_shader->setMat4("uProjection", m_projection);
	m_shader->setMat4("uView", m_view);

	m_shader->setVec3("uColour", m_quadColour);

    m_vao->bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	m_vao->unBind();
	
	m_textRenderer->render(m_frameRate.str(), {0.0f, 30.0f}, 0.5f, {0.0f, 1.0f, 0.0f}, false);
}

void PlayGroundLayer::onRenderImgui()
{
    ImGui::Begin("Main Window");

	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("This is a menu button"))
		{
			if (ImGui::MenuItem("Hello!"))
			{

			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	ImGui::ColorEdit3("Quad Colour", &m_quadColour[0]);
    ImGui::End();
}