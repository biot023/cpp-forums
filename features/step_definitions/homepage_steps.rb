Then( /^I should be able to browse to the homepage$/ ) do
  visit( "" )
  puts page.body.inspect
end
