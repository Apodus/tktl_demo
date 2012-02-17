#if __VERSION__ != 110
precision mediump float;
#endif

varying vec2 texCoord;
uniform sampler2D texture;
uniform vec4 color;

void main() {
    gl_FragColor = texture2D(texture, texCoord);
    gl_FragColor *= color;
}
