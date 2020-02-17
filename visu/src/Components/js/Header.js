import React, { Component } from 'react';
import '../css/header.css'
import GradientButton from 'react-linear-gradient-button';

class Header extends Component {

  render() {
    return (
        <div className="head">
            <h1 className='titl'>
              Corewar
            </h1>
            
            <div>
                <GradientButton className='btn'>PLAY</GradientButton>
                <GradientButton className='btn'>PAUSE</GradientButton>
                <GradientButton className='btn'>RESET</GradientButton>
          </div>
      </div>
    );
  }

}

export default Header;
