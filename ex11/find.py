import requests
import json

pokemon_name = input("Enter the name of a Pokemon: ")

if pokemon_name == "":
	print("Error: invalid name, try again!")
else:
	format_name = pokemon_name.lower()
	url = 'https://pokeapi.co/api/v2/pokemon/{}'
	res = requests.get(url.format(format_name))
	if res.status_code != 404:
		data = res.text
		request_status = res.status_code
		result = json.loads(data)
		array_size = len(result["abilities"]) - 1

		index = 0
		name = "Name: {}"
		print(name.format(pokemon_name))
		print("Abilities: ")
		while index <= array_size: 
			text_template = "- {}"
			print(text_template.format(result["abilities"][index]["ability"]["name"]))
			index += 1
	else:
		print(" Error performing search, try again!")
