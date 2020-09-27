
// fragment shader
#version 150

#define M_PI 3.1415926535897932384626433832795
#define unit 100

out vec4 outputColor;
uniform vec2 windowSize;
uniform vec2 division;

void main()
{

    float unitWidth = windowSize.x / 24;
    float unitHeight = windowSize.y / 24;

    float sx = float(int(gl_FragCoord.x)/int(unitWidth)) * float(unitWidth);
    float ex = float(int(gl_FragCoord.x)/int(unitWidth) + 1) * float(unitWidth);

    float sy = float(int(gl_FragCoord.y)/int(unitHeight)) * float(unitHeight);
    float ey = float(int(gl_FragCoord.y)/int(unitHeight) + 1) * float(unitHeight);

    // float px = 1.0 - sin((gl_FragCoord.x/windowSize.x)*M_PI);
    float psx = 1.0 - sin((sx/windowSize.x)*M_PI);
    float pex = 1.0 - sin((ex/windowSize.x)*M_PI);

    // float py = abs(sin((gl_FragCoord.y/windowSize.y)*M_PI*2.0+M_PI*0.5));
    float psy = abs(sin((sy/windowSize.y)*M_PI*2.0+M_PI*0.5));
    float pey = abs(sin((ey/windowSize.y)*M_PI*2.0+M_PI*0.5));

    outputColor = vec4(psx, psy, 0, 1.0);
}