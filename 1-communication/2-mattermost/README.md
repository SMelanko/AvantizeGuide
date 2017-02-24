# Avantize Mattermost Guide

Here is a guide how to install and configure Mattermost.

1. Download installation file and open it.

   If you haven't installed .NET yet then such dialog should be shown
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/1-communication/2-mattermost/imgs/img-1.png"/></p>
   Simply click the "Install" button to continue installation process.

2. In the Settings page click "Add new team" and fill "Name" and "URL" fields.
   ```
   Name - avantize
   URL - https://chat.avantize.com
   ```
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/1-communication/2-mattermost/imgs/img-2.png"/></p>
   In this page you can configure some options or just leave them by default.

3. Click "Gitab" button to authorize using your GitLab account.
<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/1-communication/2-mattermost/imgs/img-3.png"/></p>
4. Enter your LDAP Username and Password credentials and click "Sign in" button.

<p align="center"><img src="https://raw.github.com/SMelanko/AvantizeGuide/master/1-communication/2-mattermost/imgs/img-4.png"/></p>

   That is all. Please turn your attention to Channels:
   
   * __Off-Topic__ - for news links, memes, funny videos and other trash.
	  
   * __Town Square__ - for company notifications about holidays, corporate parties, taxes, exchange rate and etc.
   
   Tips:
   
   If you want to send a part of your code please use this scenario:
      ``` cpp
      #include <iostream>
      #include <string>
      
      int main(int argc, char* argv[])
      {
         std::string str = "Hello, World!";
	 std::cout << str << std::endl;
	 
	 return 0;
      }
      ```
