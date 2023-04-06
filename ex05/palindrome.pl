#!/usr/local/bin/perl

print "Enter a string: ";
my $str = <STDIN>;
chomp $str;

my $reverse = reverse $str;

if ($str eq $reverse) {
	print "The string is a palindrome\n"
} else {
	print "The string is not a palindromme\n";
}
