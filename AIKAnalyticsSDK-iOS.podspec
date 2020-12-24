#
# Be sure to run `pod lib lint HKLoginModule.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'AIKAnalyticsSDK-iOS'
  s.version = '5.0.0'
  s.summary          = 'AIKAnalyticsSDK-iOS.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
                        AIKAnalyticsSDK-iOS
                       DESC

  s.homepage         = 'https://code.aliyun.com/hkr-app/App_IOS_HKLoginModule'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'GongM' => 'gongm@reachauto.com' }
  s.source           = { :git => 'http://10.10.142.183:8083/gerrit/HKr_IOS_HKLoginModule', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.1'

  s.source_files = 'HKLoginModule/Classes/**/*'
  
  s.static_framework = true

  s.resource_bundles = {
     'HKLoginModule' => ['HKLoginModule/Assets/*.*']
   }

  # s.public_header_files = 'Pod/Classes/**/*.h'
    s.frameworks = 'UIKit', 'Security'
#    s.dependency 'GrowingAutoTrackKit'
#    s.dependency 'GrowingCoreKit'
#
#    s.dependency 'ReactiveCocoa', '2.5'
#    s.dependency 'SDWebImage','3.7.6'



end
