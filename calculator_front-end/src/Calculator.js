import React from 'react'
import CalculatorPanel from './CalculatorPanel'

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

  operationHandler(operation) {
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

  numberHandler(number) {
    const newNumber = this.state.numbers[this.state.numberIdx] + number;
    this.updateNumber(newNumber);
  }

  dotHandler() {
    const newNumber = this.state.numbers[this.state.numberIdx] + ".";
    if(isNaN(newNumber)) {
      return
    } 
    this.updateNumber(newNumber);
  }

  clearHandler() {
    this.setState({
      result: "",
      numbers: ["", ""],
      numberIdx: 0,
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

  updateNumber(newNumber) {
    var newNumbers = this.state.numbers;
    newNumbers[this.state.numberIdx] = newNumber;
    this.setState({
      result: newNumbers[this.state.numberIdx],
      numbers: newNumbers,
    });
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

export default Calculator;