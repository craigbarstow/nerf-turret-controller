Destroyer = {}
Destroyer.FireControls = {}

Destroyer.FireControls = function(el){
  this.el = $(el);

  this.delegateKeypress = function(e){
  }

  this.up = function(){

  }
  this.down = function(){

  }
  this.left = function(){

  }
  this.right = function(){

  }

  _.bindAll(this, 'up', 'down', 'left', 'right', 'delegateKeypress');
  $(document).on('keypress', function(e){
    console.log('Pressed!')
    this.delegateKeypress(e);
  })
}

var fireControls = new Destroyer.FireControls
