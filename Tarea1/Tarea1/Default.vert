#version 400

in vec3 VertexPosition;
in vec3 VertexColor;

out vec3 InterpolatedColor;

uniform mat4 mvpMatrix;

void main(){
	InterpolatedColor=VertexColor;
	//orden: matriz de transformaci�n, luego v�rtice
	gl_Position = mvpMatrix*vec4(VertexPosition, 1.0f);

}