
// fragment shader
#version 150

#define PI 3.1415926535897932384626433832795
#define divX 24
#define divY 41

out vec4 outputColor;
uniform vec2 windowSize;
uniform vec2 mouseCoord;

// draws a rectangle (returns 1.0 where it should be)
// the origin is at the left top.
float rect(float sx, float sy, float ex, float ey, vec2 st){
    float left = step(sx, st.x);
    float top = step(sy, 1.0 - st.y);
    float right = 1.0 - step(ex, st.x);
    float bottom = step(1.0 - ey, st.y);
    return left * top * right * bottom;
}

// draws a triangle filling the diagnal half of the rectangle()
float triangle(float sx, float sy, float ex, float ey, vec2 st) {
    float r = rect(sx, sy, ex, ey, st);
    vec2 domain = vec2(
        (1.0 - (st.x - sx) / (ex - sx)),
        ((1.0 - st.y) - sy) / (ey - sy));
    return (1.0 - step(1.0, domain.x + domain.y)) * r;
}

// converts index ints to radians
float iToDeg(int i, int limit) {
    return (float(i)/float(limit))*PI*2.0;
}

void main()
{
    vec2 st = gl_FragCoord.xy / windowSize;
    float r = 0.0;
    vec2 unit = 1.0 / vec2(float(divX), float(divY));
    vec2 wavyness = vec2(-1.8,1.0);
    // this adds mouse interaction;
    // vec2 mt = (mouseCoord / windowSize) - 0.5;
    // vec2 wavyness = vec2(-1.3, 1.0) + mt*2.0;

    for (int i=0;i<divX;i++){
        for(int j=0;j<divY;j++){
            vec2 start = unit * vec2(float(i),float(j));
            vec2 end = unit * vec2(float(i+1),float(j+1));

            // the following adds the wavyness
            vec2 degs = vec2(iToDeg(i,divX),iToDeg(j,divY)*2.0);
            vec2 dege = vec2(iToDeg(i+1,divX),iToDeg(j+1,divY)*2.0);
            start += unit * sin(degs) * wavyness;
            end += unit * sin(dege) * wavyness; 

            float pr = triangle(start.x,start.y,end.x,end.y,st);
            r += pr; // addition works like OR
        }
    }

    outputColor = vec4(vec3(r),1.0);
}