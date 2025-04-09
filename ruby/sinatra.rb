require 'sinatra'

url_mapping = {}

get '/' do
  erb :index
end

post '/shorten' do
  long_url = params[:long_url]
  short_url = rand(1000..9999).to_s
  url_mapping[short_url] = long_url
  "Shortened URL: http://localhost:4567/#{short_url}"
end

get '/:short_url' do
  long_url = url_mapping[params[:short_url]]
  redirect long_url
end
