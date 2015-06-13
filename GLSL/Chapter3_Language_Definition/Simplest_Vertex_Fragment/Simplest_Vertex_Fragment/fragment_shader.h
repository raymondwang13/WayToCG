#version 140
//Global veriables

// uniform qualified variables are changed at most once per primitive
uniform vec3 CoolestColor;
uniform vec3 HottestColor;

// Temperature contains the now interpolated per-fragment
// value of the temperature set by the vertex shader 
in float Temperature;

// out qualified global variables communicate from the fragment shader 
// to per-fragment operations (blending) and the framebuffer
out ver4 FragmentColor;

void main()
{
	// get a color between coolest and hottest colors, using the mix() built-in function
	vec3 color = mix(CoolestColor, HottestColor, Temperature);

	// make a vector of 4 floating numbers by appending an 
	// alpha of 1.0, and set this fragment's color
	FragmentColor = vec4(color, 1.0);
}