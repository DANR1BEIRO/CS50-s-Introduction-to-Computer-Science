import qrcode

img = qrcode.make(
    "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRheL2VU8WhdrpgsOhMErcmn13DChgMmaQ4XwLeLGQrGA&s=10"
)
img.save("qr.png", "PNG")
