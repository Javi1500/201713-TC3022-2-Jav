#version 400

in vec3 InterpolatedColor;

out vec4 FragColor;

uniform vec2 Resolution;

void main(){	
	/*vec2 p =gl_FragCoord.xy;
	vec2 center = vec2(300.0f,300.0f);
	vec2 q= center-p;
	if(sqrt(q.x*q.x+q.y*q.y)<150.0f){
		discard;
	}*/

	//Esta es la resolucion de la ventana en pixeles
	//vec2 resolution = vec2(600.0f, 600.0f);
	//Es la posicion del pixel en la ventana en rango (0,0), (1,1)
	vec2 p = gl_FragCoord.xy / Resolution;
	//Calculando un vector que va del pixel de centro de la ventana.
	vec2 q = p - vec2(0.5f, 0.5f);
	//Si el vector es menor a la medida se descarta.
	if(length(q)<0.5f){
		discard;
	}

	FragColor = vec4(InterpolatedColor, 1.0f);
}