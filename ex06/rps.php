<?php
echo "Choose rock, paper, or scissors: ";
$choice = trim(fgets(STDIN));

$options = ['rock', 'paper', 'scissors'];

$random_choice = $options[rand(0, 2)];

if (!(in_array($choice, $options)))
{
	echo "Error: Invalid option.\nYou must choose between: rock, paper or scissors to proceed with the game.\nYour choice: $choice\nPlease try again!\n";
	return;
}
elseif (
	$choice == 'scissor' && $random_choice == 'paper' ||
	$choice == 'paper' && $random_choice == 'rock' ||
	$choice == 'rock' && $random_choice == 'scissors'
	)
{
	echo "Congratulations! You won! The computer chose $random_choice.\n";
	return;
}
elseif ( $choice == $random_choice)
{
	echo "It's a draw !\n";
	return;
}
else 
{
	echo "Sorry, you lost. The computer chose $random_choice.\n";
	return;
}
