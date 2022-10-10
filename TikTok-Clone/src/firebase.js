import firebase from "firebase"
const firebaseConfig = {
    apiKey: "AIzaSyAczacH0XYFUdipJS8cC1xETXQHsUuLz9A",
    authDomain: "tiktok-clone-88eec.firebaseapp.com",
    projectId: "tiktok-clone-88eec",
    storageBucket: "tiktok-clone-88eec.appspot.com",
    messagingSenderId: "560939062009",
    appId: "1:560939062009:web:78f1f12a432c0184bc0828",
    measurementId: "G-KE3CRLQ6S2"
  };
  const firebaseApp = firebase.initializeApp(firebaseConfig);
  const db = firebaseApp.firestore();
  export default db;