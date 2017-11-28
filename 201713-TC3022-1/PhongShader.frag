#version 330

in vec3 InterpolatedColor;
in vec3 _InterpolatedNormal;
in vec3 _PixelPosition;
in vec3 VertexColor;
in vec2 InterpolatedTexture;


out vec4 FragColor;
uniform vec3 _LightColor;

uniform mat4 _transform;
uniform mat4 _transform2;
uniform vec3 _LightPosition;
uniform vec3 _CameraPosition;
uniform sampler2D DiffuseTexture;uniform sampler2D DiffuseTexture2;
void main()
{
	vec3 _Ambient = _LightColor * 0.1f;
	vec3 _Light =normalize(_LightPosition - _PixelPosition);
	vec3 _Diffuse = (dot(_InterpolatedNormal,_Light))*_LightColor;
	vec3 _Reflection = reflect((-1*_Light), _InterpolatedNormal);
	vec3 _View =  normalize(_CameraPosition - _PixelPosition);
	vec3 _Specular= (0.5f*(pow(dot(_View, _Reflection), 32))*_LightColor);
	vec3 _Phong = (_Ambient + _Diffuse + _Specular)*InterpolatedColor; 
	vec4 A = texture2D(DiffuseTexture, InterpolatedTexture); 
	vec4 B = texture2D(DiffuseTexture2, InterpolatedTexture);
	vec4 R = mix( A, B, 0.5f);
	FragColor = R;
	
	
}