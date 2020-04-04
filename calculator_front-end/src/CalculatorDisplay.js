import React from 'react'

function CalculatorDisplay(props) {
    return(
        <input 
            readOnly={true} 
            value={props.text}
            className="calculator-display" 
            value={props.text} 
            />
    );
}

export default CalculatorDisplay;