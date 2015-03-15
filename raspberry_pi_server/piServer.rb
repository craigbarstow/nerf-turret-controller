require 'sinatra'
require 'rubyserial'
require 'pry'

MOTION_AMOUNT = 25
#configure with raspberry pi serial port location
serialport = Serial.new '/dev/tty.usbserial-AM01YQFQ', 115200

#uncomment for local testing

get '/' do
  erb :index
end

post '/move/:direction' do
  if params[:direction] == "right"
    serialport.write("=#{MOTION_AMOUNT}|0\n")
    puts "=#{MOTION_AMOUNT}|0\n"
  elsif params[:direction] == "left"
    puts "=-#{MOTION_AMOUNT}|0\n"
    serialport.write("=-#{MOTION_AMOUNT}|0\n")
  elsif params[:direction] == "up"
    serialport.write("=0|#{MOTION_AMOUNT}\n")
    puts "=0|#{MOTION_AMOUNT}\n"
  elsif params[:direction] == "down"
    serialport.write("=0|-#{MOTION_AMOUNT}\n")
    puts "=0|-#{MOTION_AMOUNT}\n"
  end
  redirect '/'
end

post '/fire' do
  serialport.write("!0|0\n")
end

post '/manual-override/:true?' do
  if params[:true] == true
    serialport.write("=m+\n")
  elsif params[:true] == false
    serialport.write("=m-\n")
  end
end
