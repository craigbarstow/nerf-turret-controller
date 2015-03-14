require 'sinatra'
require 'rubyserial'

MOTION_AMOUNT = 20
serialport = Serial.new '/dev/ttyACM0', 115200

post '/move_x/:direction' do
  if params[:direction] == "up"
    serialport.write("#{MOTION_AMOUNT}|0\n")
  elsif params[:direction] == "down"
    serialport.write("-#{MOTION_AMOUNT}|0\n")
  end
end

post '/move_y/:direction' do
  if params[:direction] == "up"
    serialport.write("=0|#{MOTION_AMOUNT}\n")
  elsif params[:direction] == "down"
    serialport.write("=0|-#{MOTION_AMOUNT}\n")
  end
end

post '/fire' do
  serialport.write("!0|0\n")
end

post '/manual-override/:true?' do
  if params[:true] == true
    serialport.write("m+\n")
  elsif params[:true] == false
    serialport.write("m-\n")
  end
end
