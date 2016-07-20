function Coney(tempImg, tempMod) {

  this.img = tempImg;
  this.mod = tempMod;

  this.x = random(-300, 300);
  this.y = random(-300, 300);
  this.z = random(-50, 50);

  this.xDir = random(-10, 10);
  this.yDir = random(-10, 10);
  this.zDir = random(-10, 10);
  
  this.rot = random(-.05, .05);

  this.render = function() {

    push();
    translate(this.x, this.y, this.z);
    rotateX(frameCount * this.rot);
    rotateY(frameCount * this.rot);
    rotateZ(frameCount * this.rot);
    texture(this.img);
    model(this.mod);
    pop();
  }

  this.update = function() {
    this.x += this.xDir;
    this.y += this.yDir;
    this.z += this.zDir;
  }

  this.bounce = function() {
    if (this.x > 500 || this.x < -500) {
      this.xDir *= -1;
    }

    if (this.y > 500 || this.y < -500) {
      this.yDir *= -1;
    }
    if (this.z > 100 || this.x < -100) {
      this.zDir *= -1;
    }
  }

}