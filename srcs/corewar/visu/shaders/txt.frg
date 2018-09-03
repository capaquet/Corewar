#version 410 core

out vec4	fragColor;
in vec4	vtxColor;

uniform mainBlock
{
	mat4 projView;
	vec2 res;
	float ratio;
	float time;
	float time_end;
	float intro;
	float outro;
	float bass;
	float speed;
}u;


void	main()
{
	fragColor = vtxColor;
}
