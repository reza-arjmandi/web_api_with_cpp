# Web API with C++

## Introduction

In this course, I'm going to show you how `C++` can be used in modern web
development. I will implement a simple calculator web application which has
two parts:

* calculator_front-end
* calculator_back-end

In the first section I will use [`React`](https://reactjs.org/) to implement the
calculator web interface and in the second section I will use the
[`restbed`](https://github.com/Corvusoft/restbed) `C++` framework to implement
calculator API.  
Through this course you will be familiar with Single-page applications,
`JavaScript` frameworks and rest api.
Let’s start the front-end section.

## calculator Front-end

I'm going to use [`React`](https://reactjs.org/) to implement the calculator
user interface.

### What is `React`

`React` is a `JavaScript` library for building interactive web user interfaces.
In order to use `React` or any tools based in `JavaScript`, you’ll need to know
how to use npm and Node.js.

### What is `Node.js`

`JavaScript` is a client-side programming language, which means it's processed
in the browser. With `Node.js` `JavaScript` can also be used outside the
browser.

### What is `npm`

`npm` is a tool to download and install `Node.js` programs, plugins, modules and
so on.

### Install `Node.js` and `npm`

Read the following article to install and use`Node.js` and `npm`.  
[How to Install and Use Node.js and npm (Mac, Windows, Linux)](https://www.taniarascia.com/how-to-install-and-use-node-js-and-npm-mac-and-windows/)

### Install `React`

Now, to install `React`, run the following command in the terminal:  
`npm install -g create-react-app`  

If successful, you should be able to get version:  
`npm create-react-app --version`  

### Create React App

There are a few ways to use and set up `React`. Fortunately Facebook has created
`Create React App`, a tool that brings everything you need to build a `React`
app. It will create a live development server and use Webpack to automatically
compile React and JSX.  
Run the following command in the terminal to create a new react app.  

```sh
mkdir web_api_with_cpp
cd web_api_with_cpp
npx create-react-app calculator_front-end
```  

Once that finishes installing, move to the newly created directory and start the
project.  

```sh
cd calculator_front-end
npm start
```

Once you run this command, a new window will popup at `localhost:3000` with your
new `React` app.
![start React project](images/image1.png "start React project")

If you look into the project structure, you'll see a `/public` and `/src`
directory, along with the regular `node_modules`, `.gitignore`, `README.md`, and
`package.json`.
The `/src` directory will contain all `JavaScript` codes.
In `/public`, our important file is `index.html`, which has a `root` div html
element.  
In `React` you can create `components`, which are like custom, reusable HTML
elements, to quickly and efficiently build user interfaces. React also has two
interesting concepts called `state` and `props` which is used to store and
handle data.  
I'm going to design the user interface from bottom to up, I'm going to start off
by designing a simple calculator button component.  
Now, make `src/CalculatorButton.js` file and implement `CalculatorButton`
React component:  

```JavaScript
import React from 'react';

function CalculatorButton(props) {

    return(
        <input type="button"/>
    );
}

export default CalculatorButton;
```

At the first line we've imported React, then we've implemented the
`CalculatorButton` React component, and finally we've exported it in order to be
visible outside.  
We can implement `React` components through classes or simple functions, if a
React component is implemented through functions, it must get an argument.
React passes `props` of components through this argument.  
In the body function a simple `input` `html` tag is returned. This is `JSX`
syntax, `JSX` stands for `JavaScript` and `XML`. Through the `JSX` feature we
can use and combine `JavaScript` and `XML` codes together.  
If you want to know how a `React` component can be used, you can modify
`index.js` file as following:  

```JavaScript
import React from 'react';
import logo from './logo.svg';
import './App.css';
import CalculatorButton from './CalculatorButton'

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <CalculatorButton />
      </header>
    </div>
  );
}

export default App;
```

We've imported the `CalculatorButton` component then we've replaced the content
of the `header` tag with `<CalculatorButton />` tag. We can use `React`
components like `HTML` tags.  
Now you can see `CalculatorButton` component is rendered at the center of the
user interface:  
![CalculatorButton](images/image2.png "CalculatorButton")

We need to display texts inside `CalculatorButton`, in fact the
`<CalculatorButton />` tag must get an attribute like `caption="Hello World!"`
and then display the value of the `caption` attribute inside itself.  
Now set the `caption` attribute of `<CalculatorButton />` to `"Hello World!"`:  

```JavaScript
<CalculatorButton caption="Hello World!" />
```

`React` passes these attributes to components as `props`. `CalculatorButton`
components must get `caption` from `props` and then display it.  
Now update `CalculatorButton`:  

```JavaScript
function CalculatorButton(props) {

    return(
        <input 
            type="button" 
            value={props.caption}/>
    );
}
```

We've got the `caption` attribute through `props` data structure and then set it
to the `value` attribute of `input` tag.  
Now you can see, the `caption` attribute of `CalculatorButton` is rendered:  
![CalculatorButton](images/image3.png "CalculatorButton")

Now, It turns to designing all calculator buttons. Create
`src/CalculatorPanel.js` file, implement ‍‍new `CalculatorPanel` `React` component
as follows:  

```JavaScript
import React from 'react'
import CalculatorButton from './CalculatorButton'

function CalculatorPanel(props) {
  
  const captions = [
      "7", "8", "9", "/",
      "4", "5", "6", "*",
      "1", "2", "3", "-",
      "0", ".", "C", "+",
      "=",
    ];
  
  const calc_buttons = captions.map((value, index) => {
    return <CalculatorButton caption={value} />
  });

  return(
    <div>
      {calc_buttons}
    </div>
  );

}

export default CalculatorPanel;
```

We've declared `captions` array which contains all calculator buttons captions,
Then an array of `<CalculatorButton />`s is created through the `map` function,
and finally its returned inside a `<div>` `HTML` tag.  
Now, update `src/App.js` to render new `CalculatorPanel` component:  

```JavaScript
import CalculatorPanel from './CalculatorPanel'

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <CalculatorPanel />
      </header>
    </div>
  );
}
```

Now you can see `CalculatorPanel` is rendered:  
![CalculatorPanel](images/image4.png "CalculatorPanel")  

We must arrange calculator buttons in a way that it looks similar a calculator,
Now declare new styles in `src/index.css` file:

```css
.calculator-grid-container {
  display: grid;
  grid-template-columns: auto auto auto auto;
  grid-template-rows: auto auto auto auto;
  grid-gap: 10px;
  padding: 10px;
}

.calculator-equal-button {
  grid-column: 1 / span 4;
}
```

We've declared `.calculator-grid-container` in order to arrange calculator
buttons in a 4x4 grid, and also `.calculator-equal-button` is declared to style
`=` button in a way which its width equal to the calculator width.  
Now update `CalculatorPanel` component to use these styles:  

```JavaScript
function CalculatorPanel(props) {
  
  const captions = [
      "7", "8", "9", "/",
      "4", "5", "6", "*",
      "1", "2", "3", "-",
      "0", ".", "C", "+",
      "=",
    ];
  
  const calc_buttons = captions.map((value, index) => {
    return <CalculatorButton caption={value} />
  });

  return(
    <div className="calculator-grid-container">
      {calc_buttons}
    </div>
  );

}
```

We've set `className` attribute of `div` html tag element to
`calculator-grid-container`, In React we must use `className` instead of `class`
attribute in `HTML` tags, because `class` is a reserved word in `JavaScript`.  
Now update the `CalculatorButton` component to use the `calculator-equal-button`
style:

```JavaScript
function CalculatorButton(props) {

    return(
        <input 
            type="button" 
            value={props.caption}
            className={props.caption === "=" ? "calculator-equal-button" : null}/>
    );
}
```

We've set the `className` attribute to the `calculator-equal-button`, if
`props.caption` equal to the `=`. This feature of React is called conditional
rendering, through this feature we can use conditions in conjunction with `HTML`
tags.  
Now you can see arranged calculator buttons in a grid is rendered:  
![CalculatorGrid](images/image5.png "CalculatorGrid")  

Our calculator needs a display. Let's create `src/CalculatorDisplay.js` file and
implement `CalculatorDisplay` component as follows:  

```JavaScript
import React from 'react'

function CalculatorDisplay(props) {
    return(
        <input 
            readOnly={true} 
            value={props.text} 
            />
    );
}

export default CalculatorDisplay;
```

We've implemented the `CalculatorDisplay` component by an `input` `HTML` tag.
The `readOnly` attribute has been set to `true` because the `CalculatorDisplay`
value must change only by `{props.text}` attribute, and the user must not be
able to change the value of `CalculatorDisplay`.  
Now we must add the `CalculatorDisplay` component at the top of
`CalculatorPanel`:  

```JavaScript
//...
import CalculatorDisplay from './CalculatorDisplay'

function CalculatorPanel(props) {
  
  //...

  return(
    <div className="calculator-grid-container">
      <CalculatorDisplay />
      {calc_buttons}
    </div>
  );

}
```

Now you can see the `CalculatorDisplay` component is rendered as follows:  
![CalculatorDisplay](images/image6.png "CalculatorDisplay")  

Calculator buttons are disordered. We must declare a new style for
`CalculatorDisplay` in order to place it at top of the calculator and also
it's width equal to the calculator width.  
Now add the following code at the end of the `index.css`:  

```css
.calculator-display {
  grid-column: 1 / span 4;
}
```

We've declared `.calculator-display` to style `CalculatorDisplay`, Now update
`CalculatorDisplay` component as follows:  

```JavaScript
function CalculatorDisplay(props) {
    return(
        <input 
            readOnly={true} 
            value={props.text}
            className="calculator-display" 
            />
    );
}
```

We've set the `className` attribute of `input` `HTML` tag to the
`calculator-display` and you can see its result as follows:  
![CalculatorDisplay](images/image7.png "CalculatorDisplay")  

If you click on each button, nothing happens. We must implement the behavior of
calculator buttons. We're going to implement these behaviors in a new `React`
component.  
Now create `src/Calculator.js` file:  

```JavaScript
import React from 'react'
import CalculatorPanel from './CalculatorPanel'

class Calculator extends React.Component {

  operationHandler(operation){
  }

  numberHandler(number) {
  }

  dotHandler() {
  }

  clearHandler() {
  }

  equalHandler() {
  }

  render() {
    return (
        <div className="calculator-grid-container">
          <CalculatorPanel 
            numberClicked={this.numberHandler.bind(this)}
            operationClicked={this.operationHandler.bind(this)}
            dotClicked={this.dotHandler.bind(this)}
            equalClicked={this.equalHandler.bind(this)}
            clearClicked={this.clearHandler.bind(this)}
            />
        </div>
      );
  }
}

export default Calculator;
```

We've implemented calculator buttons handlers in the `Calculator` component.
In the `render` function, we've added a `CalculatorPanel` component and passed
handler functions through the `CalculatorPanel` attributes.  
I should mention that `React` components didn't bind `this` object to its
functions. As you can see, we must bind `this` object to function handlers
explicitly.  
`CalculatorPanel` component must get function handlers of buttons and calls
these handlers when buttons are clicked.  
Now update `CalculatorPanel` component as follows:  

```JavaScript
function CalculatorPanel(props) {
  
  const buttons = [
    {text: "7", handler: () => props.numberClicked("7")}, 
    {text: "8", handler: () => props.numberClicked("8")}, 
    {text: "9", handler: () => props.numberClicked("9")}, 
    {text: "/", handler: () => props.operationClicked("divide")}, 
    {text: "4", handler: () => props.numberClicked("4")}, 
    {text: "5", handler: () => props.numberClicked("5")},
    {text: "6", handler: () => props.numberClicked("6")},
    {text: "*", handler: () => props.operationClicked("multiply")}, 
    {text: "1", handler: () => props.numberClicked("1")},
    {text: "2", handler: () => props.numberClicked("2")},
    {text: "3", handler: () => props.numberClicked("3")},
    {text: "-", handler: () => props.operationClicked("subtract")},
    {text: "0", handler: () => props.numberClicked("0")},
    {text: ".", handler: () => props.dotClicked()},
    {text: "C", handler: () => props.clearClicked()},
    {text: "+", handler: () => props.operationClicked("add")},
    {text: "=", handler: () => props.equalClicked()},
  ];
  
  const calc_buttons = buttons.map((value, index) => {
    return <CalculatorButton 
      caption={value.text} 
      onClick={value.handler} />
  });

  return(
    <div className="calculator-grid-container">
    <CalculatorDisplay />
      {calc_buttons}
    </div>
  );

}
```

We've changed captions array to buttons array, and every item of this array
specified `text` and `handler` of buttons. Each handler is an arrow function
which calls the buttons handler with proper arguments. Buttons handlers are
passed through `props` data structure.  
We've updated the `map` function, and the handler of the button is passed to the
`CalculatorButton` component through the `onClick` attribute. `CalculatorButton`
component must get the handler and call it when the button is clicked.  
Now update the `CalculatorButton` component as follows:  

```JavaScript
function CalculatorButton(props) {

    return(
        <input 
            type="button" 
            value={props.caption}
            className={props.caption === "=" ? "calculator-equal-button" : null}
            onClick={props.onClick}
            />
    );
}
```

We've bound the `props.onClick` handler to the `onClick` event of `input` `HTML`
tag, and it causes every time the button is clicked, `props.onClick` is called.  
`Calculator` component must display proper values in the `CalculatorDisplay`
component when it's handlers are called.
At first `CalculatorDisplay` must be able to get its text from outside.  
Now update `CalculatorDisplay` component as follows:  

```JavaScript
function CalculatorDisplay(props) {
    return(
        <input 
            className="calculator-display" 
            readOnly={true} 
            value={props.text} 
            />
    );
}
```

We've bound the `value` attribute of `input` `HTML` tag to the `props.text`. We
can display new values through setting the `text` attribute of
`CalculatorDisplay` from outside.  
`Calculator` component must set and update the text of `CalculatorDisplay` every
time which one of the calculator buttons is clicked.  
Now update `Calculator` component as follows:  

```JavaScript
class Calculator extends React.Component {

  constructor(props) {
    super(props);
    this.state = {
      result: "",
    };
  }

  render() {
    return (
        <div className="calculator-grid-container">
          <CalculatorPanel 
            result={this.state.result} 
            numberClicked={this.numberHandler.bind(this)}
            operationClicked={this.operationHandler.bind(this)}
            dotClicked={this.dotHandler.bind(this)}
            equalClicked={this.equalHandler.bind(this)}
            clearClicked={this.clearHandler.bind(this)}
            />
        </div>
      );
  }
}
```

We've implemented the `constructor` function of the `Calculator` component in
order to initialize the `state` object. `state` is a special object in `React`
components.  
`state` is similar to `props`, but it is private and fully controlled by the
component. `state` objects can contain several independent variables.  
In the `render` function we have set the `result` attribute of `CalculatorPanel`
component to the `result` variable of `state` object.  
Every time the state is updated, `React` renders the `CalculatorPanel` component
in order to display new results.  
Now update `CalculatorPanel` component in way that it gets the `result`
attribute and updates the `CalculatorDisplay` component:  

```JavaScript
function CalculatorPanel(props) {
  
  //...
  
  return(
    <div className="calculator-grid-container">
    <CalculatorDisplay text={props.result} />
      {calc_buttons}
    </div>
  );

}
```

We've set the `text` attribute of the `CalculatorDisplay` component to the
`props.result`, and it causes the `CalculatorDisplay` component to be updated
when `props.result` is changed.  
We're going complete the implementation of function handlers in `Calculator`
component, We're going to start by `numberHandler`:  

```JavaScript
class Calculator extends React.Component {

  constructor(props) {
    super(props);
    this.state = {
      result: "",
      numbers: ["", ""],
      numberIdx: 0,
    };
  }

  numberHandler(number) {
    const newNumber = this.state.numbers[this.state.numberIdx] + number;
    this.updateNumber(newNumber);
  }

  updateNumber(newNumber) {
    var newNumbers = this.state.numbers;
    newNumbers[this.state.numberIdx] = newNumber;
    this.setState({
      result: newNumbers[this.state.numberIdx],
      numbers: newNumbers,
    });
  }

}
```

We've added new variables to `state` object, `numbers` array which has two empty
strings, `numberIdx` variable which is set to `0`. All operations of this
calculator are binary operations, which means operations need two numbers. We're
going to store these two numbers in `numbers` array. `numberIdx` specifies which
number the user has entered, first number or second number.  
`numberHandler` is called when the user clicks on each number button, and
number is passed to the handler through the `number` argument. In this function
we've updated the `numbers` array in `state` object.  
Beer in mind, we must update `state` objects only through the `setState`
function.  
Now we're going to complete the implementation of `dotHandler` function:  

```JavaScript
dotHandler() {
    const newNumber = this.state.numbers[this.state.numberIdx] + ".";
    if(isNaN(newNumber)) {
      return
    } 
    this.updateNumber(newNumber);
}
```

This function adds `.` to the numbers in order to cast them to the float
numbers. And finally updates the `numbers` array in `state` object through
`updateNumber` function which is implemented in the previous step.  
Now it turns to `operationHandler`:  

```JavaScript

class Calculator extends React.Component {

  constructor(props) {
    super(props);
    this.state = {
      result: "",
      numbers: ["", ""],
      numberIdx: 0,
      operation: "",
    };
  }

  operationHandler(operation){
    if(this.state.numberIdx === 1) {
      this.equalHandler();
      return;
    }

    if( (operation === "subtract" || operation === "add") &&
          this.state.numbers[this.state.numberIdx] === "") {
      this.numberHandler(operation === "subtract" ? "-" : "+");
      return;
    }

    this.setOperation(operation);
  }

  setOperation(operation){
    this.setState({operation: operation});
    this.nextNumber();
  }

  nextNumber() {
    const newIdx = this.state.numberIdx === 0 ? 1 : 0;
    this.setState({
      result: this.state.numbers[newIdx],
      numberIdx: newIdx,
    });
  }

}
```

We've added a new `operation` variable to the `state` object in order to store
operations the which user clicked.  
`operationHandler` is called when of of these operations `+`, `-`, `*` and `/`
is clicked. We've updated the `numberIdx` and  `operation` variable.  
Also when users click on `+` or `-` buttons which didn't enter any numbers
before, then we add a `+` or `-` in front of the number. And if a user
enters two numbers and then clicks on one of the operation buttons then we call
the `equalHandler` function, which it equals to click on `=` button.  
Now implement `equalHandler`:  

```JavaScript
setResult(result){
  const newNumbers = [result, ""];
  const newNumberIdx = 0;
  this.setState({
    result: newNumbers[newNumberIdx],
    numbers: newNumbers,
    numberIdx: newNumberIdx,
    operation: "",
  });
}

equalHandler() {
  if(this.state.numbers[0] === "" || this.state.numbers[1] === "") {
    return
  }
  this.props.calculatorApi.calculate(
    this.state.numbers[0], 
    this.state.numbers[1], 
    this.state.operation, 
    (result)=> {
      this.setResult(result);
    });
}
```

We've supposed that an object is passed through `props` object called
`calculatorApi`. Through this object we can call the calculator API. This object
has a function called `calculate` which gets the first number, second number,
operation and a handler as arguments.  
We've called this function in order to send numbers and operation to the
Back-end API, when the result is gotten ready, the handler is called and the
result is passed through the handler argument.  
Finally we're going to implement `clearHandler`:  

```JavaScript
clearHandler() {
  this.setState({
    result: "",
    numbers: ["", ""],
    numberIdx: 0,
  });
}
```

`clearHandler` sets the `state` object to initial state.  
Now we must implement the `CalculatorApi` component. create
`src/CalculatorApi.js` class as follows:  

```JavaScript
class CalculatorApi {

    calculate(number1, number2, operation, handler) {

    }

}

export default CalculatorApi;
```

`CalculatorApi` is a simple `JavaScript` class, it's not a `React` component.
As we need, `CalculatorApi` has a `calculate` function which gets two numbers,
an operation and a handler.  
Now implement `calculate` function as follows:  

```JavaScript
class CalculatorApi {

    constructor(serviceAddress) {
        this.serviceAddress = serviceAddress;
    }

    makeURL(number1, number2, operation) {
        const resource = operation + "/" + number1 + "/" + number2;
        return new URL(resource, this.serviceAddress);
    }

    calculate(number1, number2, operation, handler) {
        fetch(this.makeURL(number1, number2, operation))
        .then(res => res.json())
        .then((response)=> {
            handler(response["result"]);
          },
          (err)=> {
            handler(err);
            console.log(err);
          }
        );
    }
}
```

`calculate` function uses the `fetch` API in order to communicate
with the calculator API. `CalculatorApi` also gets calculator API address
thorough its `constructor` function.  
We must create an object from `CalculatorApi` and pass it to the
`Calculator` class. Now update `App.js`:  

```JavaScript
import Calculator from './Calculator'
import CalculatorApi from './CalculatorApi'

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <Calculator calculatorApi={new CalculatorApi('http://127.0.0.1:8080')} />
      </header>
    </div>
  );
}
```  

We've changed the `CalculatorPanel` component to `Calculator` component. And
also we've created an object from the `CalculatorApi` component and passed it to
the `Calculator` component through the `calculatorApi` attribute.  
Congratulations.!  
You've completed the calculator front-end section. Now Let's dive into the
calculator back-end section.  

## calculator Back-end

We've going to use `restbed` C++ framework to implement calculator API.  

### What is `restbed`

`restbed` is a C++11 framework which enables you to implement RESTful APIs. For
further information visit [it's page](https://github.com/Corvusoft/restbed).  

### Install `restbed`

If you have a `Linux` machine, you can run the following command in the terminal
to install `restbed`:  

```sh
sudo apt-get update
sudo apt install librestbed-dev
```

Otherwise you can build and install it through `cmake`, read `restbed`
[documentation for details](https://github.com/Corvusoft/restbed).  

### What is `cmake`

`cmake` is a cross-platform, open-source build system. `cmake` is used to build
test and package C++ software.  
We're going to use `cmake` to build calculator API.  

### Install `cmake`

If you have a `Linux` machine, you can run the following command in the terminal
to install `cmake`:  

`sudo apt-get install cmake`

Otherwise you can install it through [this link](https://cmake.org/download/).  

### Create calculator API application

Create new directory in the `web_api_with_cpp` directory called
`calculator_back-end`:  

```sh
cd ..
mkdir calculator_back-end
```

Now create `calculator_back-end/calculator_API.cpp` file and implement an empty
`main` function:  

```C++
#include <memory>
#include <cstdlib>
#include <string>

#include <restbed>

using namespace std;
using namespace restbed;

int main(int argc, char** argv)
{

  return 0;
}
```

We've included `restbed` library and also some other standard library which is
needed to implement calculator_API application.  
`restbed` framework has a class called `Resource`. `Resource` class helps us to
implement and publish API functionalities.  
Now create a `Resource` object for calculator functionality:  

```C++
int main(const int, const char**)
{
  auto calc_resource = make_shared<Resource>();
  return 0;
}
```

We've create an object from `Resource` class called `calc_resource`.  
Every resource in RESTful APIs must associate with an url. We can associate an
url to `calc_resource` through `set_path` function:  

```C++
  calc_resource->set_path(
    "/{operation: add|subtract|multiply|divide}"
    "/{num1: [-+]?[0-9]*\\.?[0-9]*}"
    "/{num2: [-+]?[0-9]*\\.?[0-9]*}");
```

We've set an url to `calc_resource` object through `set_path` function. This url
has three part:  

* `operation`
* `num1`
* `num2`

It means we can reach to the `calc_resource` through an url like this:  
`/add/2/3`  

We've used regular expression syntax in order to filter each part of the url.
`operation` part must accept only `add`, `subtract`, `multiply` and `divide`
parameters which specify the calculator functionality. `num1` and `num2`
must accept only float or integral numbers which specify calculator
functionality operands.  
Every `Resource` object must have a handler which is called when resource is
requested by a client. We can set handler of `Resource` object through
`set_method_handler` function:  

```C++
void calc_handler(const shared_ptr<Session> session)
{
}

int main(const int, const char**)
{
  auto calc_resource = make_shared<Resource>();
  calc_resource->set_path(
      "/{operation: add|subtract|multiply|divide}"
      "/{num1: [-+]?[0-9]*\\.?[0-9]*}"
      "/{num2: [-+]?[0-9]*\\.?[0-9]*}");
  calc_resource->set_method_handler("GET", calc_handler);
  
  return 0;
}
```

We've set `calc_handler` to `calc_resource` object as a handler.
`set_method_handler` gets two arguments, first argument specifies `http` method
and second argument specifies function handler. Every time `calc_resource` is
requested `calc_handler` is called and an object is passed to the handler called
`session`. Through the `session` object we can get any information about
requests and send results to the client:  

```C++
void calc_handler(const shared_ptr<Session> session)
{
    const auto& request = session->get_request();
    const auto operation = request->get_path_parameter("operation");
    auto num1 = atof(request->get_path_parameter("num1").c_str());
    auto num2 = atof(request->get_path_parameter("num2").c_str());
}
```

We've got the `request` object from the `session` object through the
`get_request` function. Then we've got the `operation`, `num1` and `num2`
parts of the url through the `get_path_parameter` function. Then we've converted
the `num1` and `num2` values to float numbers.  
Now we must prepare the result:  

```C++
void calc_handler(const shared_ptr<Session> session)
{
    //...

    auto result = string("{\"result\": ");

    if(operation == "add")
    {
        result +=  to_string(num1 + num2);
    }
    else if(operation == "subtract")
    {
        result += to_string(num1 - num2);
    }
    else if(operation == "multiply")
    {
        result += to_string(num1 * num2);
    }
    else if(operation == "divide")
    {
        result += to_string(num1 / num2);
    }

    result += "}";
}
```

Then we've prepared the result in the format of `JSON` data structure. Finally
we must send data to the client:  

```C++
void calc_handler(const shared_ptr<Session> session)
{
    //...
    session->close(
        OK, result, {{"Content-Length", to_string(result.size())}});
}
```

We've sent data through calling the `close` function of `session` object.
`close` function gets three arguments, `http` status code, message body and
`http` headers. We've passed `OK` as `http` status code, `result` JSON data as
message body and a `std::mulitmap` object as `http` headers which contains a
field called `Content-Length` specifying length of message body.  
Now we must publish `calc_resource` :  

```C++
int main(const int, const char**)
{
    //...

    auto settings = make_shared<Settings>();
    settings->set_port(8080);
    settings->set_default_header("Connection", "close");
    settings->set_default_header( "Access-Control-Allow-Origin", "*");

    Service service;
    service.publish(calc_resource);
    service.start(settings);

    return EXIT_SUCCESS;
}
```

We've created an object from `Setting` class. This object is used to specify
web service settings. We've set port number and two default `http` headers
through this object. `Access-Control-Allow-Origin` headers is set to `*` in
order to prevent `CORS` errors, for further information about this error you can
read
[this article](https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS/Errors).  
Then we've created an object from the `Service` class and published the
`calc_resource` through calling the `publish` function. Finally we've started
the service.  
Now we must build the `calculator_API.cpp` file.

### build calculator Back-end

We're going to build calculator back-end through `cmake`. Create
`calculator_back-end/CMakeLists.txt` file and copy following code into it:  

```CMAKE
cmake_minimum_required(VERSION 3.0)

project(calculator_API)

add_executable(calculator_API calculator_API.cpp)
target_link_libraries(calculator_API restbed)
set_property(TARGET calculator_API PROPERTY CXX_STANDARD 17)
```

Now you can build project through running the following command in the terminal:  

```sh
cmake -Hcalculator_back-end -Bcalculator_back-end/build
cmake --build calculator_back-end/build --config Release --target all
```

Now you can run calculator API through running following command in the
terminal:  

`calculator_back-end/build/calculator_API`

Congratulations!  
`calculator_API` is completed, Now you can work with calculator.
