var cone;
var img;
var mod = [];

function setup() {
  createCanvas(600, 600, WEBGL);
  cone = loadModel('assets/cone.obj', true); // wait forever
  img = loadImage('assets/cone.jpg');
  for (var i = 0; i < 30; i++) {
    mod[i] = new Coney(img, cone);
  }
}

function draw() {
  background(0);
  for (var i = 0; i < mod.length; i++) {

    mod[i].render();
    mod[i].update();
    mod[i].bounce();
  }

}