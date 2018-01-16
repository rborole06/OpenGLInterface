class Rahul :public IOpenGL
{
private:

public:
	enum SCENE_NUMBER
	{
		MAIN,
		PRATIK,
		PRAVEEN,
		RAHUL,
		SURAJ
	};

	Rahul();
	static IOpenGL* GetInstance();
	virtual BOOL SceneHandler(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) = 0;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Resize(int width, int height) = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void SceneTransition() = 0;
	virtual void UnInitialize() = 0;
};

Rahul::Rahul()
{

}

Rahul::GetInstance()
{
	IOpenGL* ptr = new Rahul();
	return ptr;
}

Rahul::Initialize()
{

}

Rahul::Update()
{

}

Rahul::Resize()
{

}

Rahul::Render()
{

}

Rahul::SceneTransition()
{

}

Rahul::UnInitialize()
{

}