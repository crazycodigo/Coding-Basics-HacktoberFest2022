import instaloader
insta = instaloader.Instaloader()
pfp = input("Please enter the username: ")
insta.download_profile(pfp, profile_pic_only=True)