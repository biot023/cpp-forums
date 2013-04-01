require "capybara/cucumber"
# require "capybara/dsl"
require "capybara/webkit"

Capybara.default_driver = :webkit
Capybara.run_server = false
Capybara.app_host = "http://localhost:3000"

$svr_process = IO::popen( "bin/server -p 3000", :err => [ :child, :out ] )
# puts $svr_process.read
at_exit { $svr_process.close }
