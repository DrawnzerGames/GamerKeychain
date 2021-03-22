# GamerKeychain
The Utility Plugin for Unreal Engine that enables the game to persist user's credentials securly in OS's credential vault (Credentials Manager for Windows 10, Keystore for Android, Secret Service for linux, Keychain for Mac-OSX).

This plugin is wrappers above the native OS's credential's vault and will choose respective implementation based on OS.

**FEATURES SUPPORTED ON ALL OS.**
1. Save in vault.
2. Read from vault.
3. Delete from vault.

**HOW TO USE**
1. If you are experienced C++ UE4 dev, its piece of cake.
2. For blueprinters, I have exposed Async task nodes for save, read and delete.
   
   ![image](https://user-images.githubusercontent.com/5199691/112023256-170cd800-8b59-11eb-96be-1ca0e9a73519.png)


**PLUGIN STATE**
1. Windows - Fully functional.
2. Android - Abstract implementation done, full support to be added soon.
3. Linux - Abstract implementation done, full support to be added soon.
4. Mac - My game don't target Mac, but PRs are welcome.
5. iOS - My game don't target iOS, but PRs are welcome.
6. Xbox - The Xbox OS is custom version of Windows, so this plugin should work there too.
7. PlayStation - Don't know.


**TODO for production**

Wrap the system calls inside a thread, as these system calls doesn't offer any callback mechanism, so using on main thread is very risky.


