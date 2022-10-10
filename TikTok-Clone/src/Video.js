import React,{useRef,useState} from 'react'
import VideoFooter from "./VideoFooter"
import VideoSideBar from "./VideoSidebar"
import "./Video.css"
function Video({
    url,
    channel,
    description,
    shares,
    messages,
    likes,
    song
}) {
    const [play,setPlay]=useState(false);
    const videoRef=useRef(null);
    const onVideoPress=()=>{
        if(play){
        videoRef.current.pause();
        setPlay(false);
    }
else{
    videoRef.current.play();
    setPlay(true);
}
}
    return (
        <div className="video"> 
           <video className="video__player"
           loop
           ref={videoRef}
           onClick={onVideoPress}
           src={url}></video>
            {/* <VideoFooter/> */}
            <VideoFooter channel={channel} description={description} song={song}/>
            {/* <VideoSideBar/> */}
            <VideoSideBar likes={likes} messages={messages} shares = {shares}/>
        </div>
    )
}

export default Video;
