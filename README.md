# Linked-Lists-Editor-Buffer

For this assignment, you will use doubly-linked lists to implement the buffer of a (very simple)
text editor. The buffer is the data structure that represents the text being edited, along with in-
formation about the current insertion point. It efficiently supports operations to insert and delete
characters at the insertion point and to move the insertion point. The code for managing the buffer
is typically independent of the code for managing the display of the buffer contents (i.e., what the
user actually sees). More accurately, an editor typically consists of three components: the buffer,
a view of the buffer (some sort of display), and a controller that accepts user input. At a high
level, the controller is really an infinite loop that executes the following steps, where the buffer is
initially empty:

(1) Update the view, which will display the text in the buffer, along with an indication of where
in the text the next event (see the next step) will have an effect.

(2) Wait for an event that indicates that the user wishes to change the buffer. Typical events
are a key press of an ordinary character (indicating that the user wishes to insert a character
into the buffer), a key press of the backspace or delete key (indicating that the user wishes
to delete a character from the buffer), or a key press of an arrow key (indicating that the
user wishes to change the position at which the next event will affect the buffer).

(3) Modify the buffer according to the event.

The driver program provided in the code distribution implements a text-based version of a
controller and view by presenting the user with a menu of options (like insert a character, delete
the character to the left of the insertion mark, etc.) and displaying the contents of the buffer as
a string. Provided the buffer structure implements an appropriate interface, neither the controller
nor the view need to know anything about how it represents the text and insertion point. So your
job is to implement the buffer structure so that it implements a specific interface.

In a bit more detail, you will write a module in which you define the following:

•A node structure for doubly-linked lists of characters.

•A buffer structure that has a doubly-linked list of characters (using your node structure)
and a reference to one of those nodes to represent the current insertion point.

•An insertion function that inserts a new character into the buffer at the current insertion
point.

•A deletion function that deletes the character to the left of the current insertion point.

•A deletion function that deletes the character to the right of the current insertion point.

•Two functions to move the insertion point to the left and the right.

•A function to set the insertion point to a specific position.

•A function that returns the contents of the buffer as a structure with two fields: a string
representing the contents to the left of the insertion point and a string representing the
contents to the right of the insertion point. The view uses this function to display the
contents buffer and the insertion mark.
