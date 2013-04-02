require "capybara/cucumber"
# require "capybara/dsl"
# require "capybara/webkit"
require "capybara/poltergeist"

$svr_process = IO::popen( "bin/server --port 3000", :err => [ :child, :out ] )

Capybara.default_driver = :poltergeist
Capybara.run_server = false
Capybara.app_host = "http://0.0.0.0:3000"

at_exit { puts `kill -9 #{$svr_process.pid }` }
