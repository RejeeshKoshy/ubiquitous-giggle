<?php
class Animal {
    public function speak() {
        return "Animal speaks";
    }
}

class Dog extends Animal {
    public function speak() {
        return "Dog barks";
    }
}

class Cat extends Animal {
    public function speak() {
        return "Cat meows";
    }
}

$dog = new Dog();
$cat = new Cat();
echo $dog->speak(); // Dog barks
echo "<br>";
echo $cat->speak(); // Cat meows
?>
