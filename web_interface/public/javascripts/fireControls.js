Destroyer = {}
Destroyer.FireControls = {}

Destroyer.FireControls = function(){
  var turretHost = 'http://localhost:4567/'

  delegateKeypress = function(pressedKey){
    switch (pressedKey) {
      case 119:
        up();
        break;
      case 115:
        down();
        break;
      case 97:
        left();
        break;
      case 100:
        right();
        break;
    }
  }

  up = function(){
    $.post( turretHost + 'move/down')
      .done(function() {
        'Pressed Up.'
      })
      .fail(function(data){
        'Up shit itself:' + data
      })
  }
  down = function(){
    $.post( turretHost + 'move/down')
      .done(function() {
        'Pressed Down.'
      })
      .fail(function(data){
        'Down shit itself:' + data
      })
  }
  left = function(){
    console.log()
    $.post( turretHost + 'move/left')
      .done(function() {
        'Pressed Left.'
      })
      .fail(function(data){
        'Left shit itself:' + data
      })
  }
  right = function(){
    $.post( turretHost + 'move/right')
      .done(function() {
        'Pressed Right.'
      })
      .fail(function(data){
        'Right shit itself:' + data
      })
  }

  // _.bindAll(this, 'up', 'down', 'left', 'right');

  $(document).keypress(function(e){
    delegateKeypress(e.keyCode);
  });
}

var fireControls = new Destroyer.FireControls
