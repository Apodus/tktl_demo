uniform mat4 MVPMatrix;
attribute vec4 vertexPosition;
attribute vec2 textureCoordinate;

varying vec2 texCoord;

void main() {
    gl_Position = MVPMatrix * vertexPosition;
    texCoord = textureCoordinate;
}
