#
# Be sure to run `pod lib lint HKLoginModule.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'AIKAnalyticsSDK-iOS'
  s.version = '1.0.0'
  s.summary          = 'AIKAnalyticsSDK-iOS.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
                        AIKAnalyticsSDK-iOS
                       DESC

  s.homepage         = 'https://github.com/FatsoCat/AIKAnalyticsSDK-iOS'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'GongM' => 'gongm@reachauto.com' }
  s.source           = { :git => 'https://github.com/FatsoCat/AIKAnalyticsSDK-iOS', :tag => s.version }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'
  s.requires_arc = true
  s.vendored_frameworks = 'AIKAnalyticsSDK.framework'
  s.frameworks = 'Foundation','UIKit','CoreLocation','Security','CoreTelephony','SystemConfiguration','AdSupport','JavaScriptCore','WebKit'
  s.libraries ='icucore','sqlite3'
  s.pod_target_xcconfig = {
    'OTHER_LDFLAGS' => '-lObjC'
  }
  s.static_framework = true

end
