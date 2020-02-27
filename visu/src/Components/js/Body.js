import React, { Component } from 'react';
import '../css/body.css'
import Player from './Player'

class Body extends Component {

  render() {
    return (
        <div className="body , center">
            <div className="shadow , visu">
                ok
            </div>
            <div className="shadow , visuInfo">
                <Player />
                <Player />
                <Player />
                <Player />
            </div>
      </div>
    );
  }

}

export default Body;
